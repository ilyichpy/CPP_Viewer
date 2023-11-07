#ifndef PARSER_CONTROLLER_H_
#define PARSER_CONTROLLER_H_

#include "../model/s21_parser.h"
#include "s21_settings.h"

namespace s21 {
class ParserController {
 public:
  ParserController();
  void makeModel(std::string path);
  void cleanModel();
  double grad_to_rad(double grad);
  void rotation_x(double angle);
  void rotation_y(double angle);
  void rotation_z(double angle);
  void move_x(double a);
  void move_y(double a);
  void move_z(double a);
  void scale_x(double k);
  void scale_y(double k);
  void scale_z(double k);
  void scale_xyz(double k);
  Model getModel();

  //  private:
  Parser &parser = Parser::getInstance();
};

}  // namespace s21

#endif  // PARSER_CONTROLLER_H_
