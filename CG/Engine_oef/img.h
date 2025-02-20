//
// Created by kali on 2/20/25.
//

#ifndef IMG_H
#define IMG_H

#include <vector>
#include "LSystem2D.h"
#include <string>

class img {
public:
  img(int width, int height);
  void drawLine(int x0, int y0, int x1, int y1, double r, double g, double b);
  void setBackground(double r, double g, double b);
  void write(const std::string& filename);

private:
  int width;
  int height;
  std::vector<std::vector<std::vector<double>>> pixels;
};
#endif //IMG_H
