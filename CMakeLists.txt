cmake_minimum_required(VERSION 3.9)
project(ARPG_StoryBoard CXX)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-dev") #Affiche TOUS les warnings en mode debug
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/SDL2/cmake") #chemin pour accéder au fichier cmake
#qui vont trouver les différents fichiers nécessaire pour utiliser SDL2

set(SDL2_IMAGE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/include")
set(SDL2_IMAGE_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/lib/libSDL2_image.dll.a")

set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/include")
set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/lib/libSDL2.dll.a")
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)

file(GLOB SOURCES
        src/*.cpp
        include/*.h
        )
add_executable(Dice_Game_Project ${SOURCES} include/requirement.h src/WindowContent.cpp include/WindowContent.h include/Input.h)
include_directories(${PROJECT_SOURCE_DIR}/include ${SDL2_IMAGE_INCLUDE_DIR}) #inclusion des dossier nécessaire pour le
#développement avec SDL2
target_link_libraries(Dice_Game_Project ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ) #inclusion des bibliothèques nécessaire pour
#le développement avec SDL2