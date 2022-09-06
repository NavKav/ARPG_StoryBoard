//
// Created by navid on 11/06/2022.
//
#include "game/map/MapGenerator.h"

using namespace std;

MapGenerator::MapGenerator(unsigned int X, unsigned int Y, unsigned int seed) :
_X(X),
_Y(Y),
_seed(seed)
{
    srand(_seed);
    _mapGround = new Uint*[_X];
    _mapLiquid = new Uint*[_X];
    for (unsigned int i = 0; i < _X; i++) {
        _mapGround[i] = new Uint[_Y];
        _mapLiquid[i] = new Uint[_Y];
    }
    blank();
}

MapGenerator::~MapGenerator() {
    for (unsigned int i = 0; i < _X; i++) {
        delete[] _mapGround[i];
        delete[] _mapLiquid[i];
    }
    delete[] _mapGround;
    delete[] _mapLiquid;
}

void MapGenerator::blank() {
    for (unsigned int i = 0; i < _X; i++) {
        for (unsigned int j = 0; j < _Y; j++) {
            _mapGround[i][j] = 1;
            _mapLiquid[i][j] = 143;
        }
    }
}

void MapGenerator::display() {
    for (unsigned int i = 0; i < _X; i++) {
        for (unsigned int j = 0; j < _Y; j++) {
            cout << _mapGround[i][j];
            cout << _mapLiquid[i][j];
        }
        cout << endl;
    }
}

void MapGenerator::setCurrentMap(unsigned int cm) {
    switch (cm) {
        case GROUND:
            _currentMap = _mapGround;
            break;
        case LIQUID:
            _currentMap = _mapLiquid;
            break;
        default :
            _currentMap = _mapGround;
            break;
    }
}

Uint& MapGenerator::operator()(unsigned int x, unsigned int y) {
    if (x <_X && x >= 0 && y >= 0 && y <_Y) {
        return _currentMap[x][y];
    }
    return _currentMap[0][0];
}

bool MapGenerator::sameTile(unsigned int x, unsigned int y, unsigned int d) {
    switch (d) {
        case 1:
            if (x <= 0 || y <= 0 || _currentMap[x - 1][y - 1] != _currentMap[x][y])
                return false;
            return true;
        case 2:
            if (y <= 0 || _currentMap[x][y - 1] != _currentMap[x][y])
                return false;
            return true;
        case 3:
            if (x >= _X - 1 || y <= 0 || _currentMap[x + 1][y - 1] != _currentMap[x][y])
                return false;
            return true;
        case 4:
            if (x >= _X - 1 || _currentMap[x + 1][y] != _currentMap[x][y])
                return false;
            return true;
        case 5:
            if (x >= _X - 1 || y >= _Y - 1 || _currentMap[x + 1][y + 1] != _currentMap[x][y])
                return false;
            return true;
        case 6:
            if (y >= _Y - 1 || _currentMap[x][y + 1] != _currentMap[x][y])
                return false;
            return true;
        case 7:
            if (x <= 0 || y >= _Y - 1 || _currentMap[x - 1][y + 1] != _currentMap[x][y])
                return false;
            return true;
        default :
            if (x <= 0 || _currentMap[x - 1][y] != _currentMap[x][y])
                return false;
            return true;
    }
}

/* Config :
 * scale  = 100
 * persistance= 0.5
 * lacunarity = 2
 * octave = 5
 * amplitude = 1
 * frequency = 1
 * */
void MapGenerator::generate() const {
    float scale = 25, persistance= 0.5, lacunarity = 2;
    int octave = 5;
    double tmp;
/*
    double offsetX = 0, offsetY = 0;

    Upair offset[octave];
    for (unsigned int index = 0; index < octave; index ++) {
        offset[index].first = (rand()%20) - 10 + offsetX;
        offset[index].second = (rand()%20) - 10 + offsetY;
    }
*/
    PerlinNoise perlinNoise(_seed);
    double i, j;
    auto X = (double)_X, Y = (double) _Y;

    double hX = X/2., hY =Y/2.;
/*
    double maxNoiseHeight = 3.40282347E+38;
    double minNoiseHeight = -3.40282347E+38;
*/

    for (j = 0; j < Y; j++) {
        for (i = 0; i < X; i++) {
            float amplitude = 1;
            float frequency = 1.5;
            float noiseHeight = 0;
            for (unsigned int aux = 0; aux < octave; aux++) {
                double sx = (i - hX) / scale * frequency /*+ offset[aux].first*/;
                double sy = (j - hY) / scale * frequency /*+ offset[aux].second*/;
                tmp = perlinNoise.noise(sx, sy) * 2 - 1;
                noiseHeight += tmp * amplitude;

                amplitude *= persistance;
                frequency *= lacunarity;
            }

/*
            if (noiseHeight > maxNoiseHeight) {
                maxNoiseHeight = noiseHeight;
            } else if (noiseHeight < minNoiseHeight) {
                minNoiseHeight = noiseHeight;
            }
*/
            Uint a = i, b = j;
            if (noiseHeight < -0.1)
            {
                cout << ' ';
                _mapGround[a][b] = 80;
                _mapLiquid[a][b] = 66;
            }
            else if (noiseHeight < 0.4)
            {
                cout << (char)176;
                _mapGround[a][b] = 81;
            }
            else if (noiseHeight < 0.8)
            {
                cout << (char)177;
                _mapGround[a][b] = 39;
            }
            else if (noiseHeight < 0.9)
            {
                cout <<(char)178;
                _mapGround[a][b] = 39;
            }
            else
            {
                cout << (char)219;
                _mapGround[a][b] = 39;
            }
        }
        cout << '\n';
    }
}