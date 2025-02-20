#include "img.h"
#include <fstream>
#include <cmath>

img::img(int width, int height) : width(width), height(height) {
    pixels.resize(height, std::vector<std::vector<double>>(width, std::vector<double>(3, 0.0)));
}
