//
// Created by navid on 05/09/2021.
//

#ifndef DICE_GAME_PROJECT_CONCURRENTRUNNERBASE_H
#define DICE_GAME_PROJECT_CONCURRENTRUNNERBASE_H
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <thread>

// Object that runs multiple functions, each in its own thread, starting them as simultaneously as possible.
class ConcurrentRunner final
        {
        public:
            template<typename... BackgroundThreadsFunctions>
            explicit ConcurrentRunner(const std::function<void()>& this_thread_function, const BackgroundThreadsFunctions&... background_threads_functions)
            : _this_thread_function{this_thread_function}
            , _num_threads_total{1 + sizeof...(BackgroundThreadsFunctions)}
            {
                this->PrepareBackgroundThreads({ background_threads_functions... });
            }


            // Executes `ThreadProc` for this thread's function and waits for all of the background threads to finish.
            void run()
            {
                this->ThreadProc(_this_thread_function);

                for (auto& background_thread : _background_threads)
                    background_thread.join();
            }

            void add(std::function<void()> f) {
                _background_threads.emplace_back([this, function = f]()
                {
                    this->ThreadProc(function);
                });
                _num_threads_total ++;
            }

        private:
            // Creates the background threads: each of them will execute `ThreadProc` with its respective function.
            void PrepareBackgroundThreads(const std::vector<std::function<void()>>& background_threads_functions)
            {
                // Iterate through the vector of the background threads' functions and create a new thread with `ThreadProc` for each of them.
                _background_threads.reserve(background_threads_functions.size());
                for (const auto& background_thread_function : background_threads_functions)
                {
                    _background_threads.emplace_back([this, function = background_thread_function]()
                    {
                        this->ThreadProc(function);
                    });
                }
            }

            // Procedure that will be executed by each thread, including the "main" thread and all background ones.
            void ThreadProc(const std::function<void()>& function)
            {
                // Increment the `_num_threads_waiting_for_start_signal` while the mutex is locked, thus signalizing that a new thread is ready to start.
                std::unique_lock<std::mutex> lock{_mutex};
                ++_num_threads_waiting_for_start_signal;
                const bool ready_to_go = (_num_threads_waiting_for_start_signal == _num_threads_total);
                lock.unlock();

                if (ready_to_go)
                {
                    // If this thread was the last one of the threads which must start simultaneously, notify all other threads that they are ready to start.
                    _cv.notify_all();
                }
                else
                {
                    // If this thread was not the last one of the threads which must start simultaneously, wait on `_cv` until all other threads are ready.
                    lock.lock();
                    _cv.wait(lock, [this]()
                    {
                        return (_num_threads_waiting_for_start_signal == _num_threads_total);
                    });
                    lock.unlock();
                }

                // Execute this thread's internal function.
                function();
            }

        private:
            std::function<void()> _this_thread_function;
            std::vector<std::thread> _background_threads;

            unsigned int _num_threads_total;
            unsigned int _num_threads_waiting_for_start_signal{0}; // counter of the threads which are ready to start running their functions
            mutable std::mutex _mutex; // mutex that protects the counter
            std::condition_variable _cv; // waited on by all threads but the last one; notified when the last thread increments the counter
        };

#endif //DICE_GAME_PROJECT_CONCURRENTRUNNERBASE_H
