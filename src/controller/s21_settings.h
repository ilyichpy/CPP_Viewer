#ifndef SETTINGS_H_
#define SETTINGS_H_

namespace s21 {
typedef struct rgb_color {
  float r;
  float g;
  float b;
} RGB;

class Settings {
 public:
  RGB lineColor;
  RGB vertexColor;
  RGB bgColor;
  int lineType;
  double lineThickness;
  int vertexType;
  float vertexSize;
  int projectionType;
};
};  // namespace s21

#endif  // SETTINGS_H_