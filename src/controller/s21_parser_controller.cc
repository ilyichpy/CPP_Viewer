#include "./s21_parser_controller.h"

using namespace s21;

ParserController::ParserController() {}

/**
 * @brief create a model that the path variable points to
 */
void ParserController::makeModel(std::string path) { parser.start(path); }

/**
 * @brief clear the created model
 */
void ParserController::cleanModel() { parser.remove_parser(); }

/**
 * @brief converts degrees to radians
 */
double ParserController::grad_to_rad(double grad) {
  return parser.result.matrix.grad_to_rad(grad);
}

void ParserController::rotation_x(double angle) {
  parser.result.matrix.rotation_x(angle);
}

void ParserController::rotation_y(double angle) {
  parser.result.matrix.rotation_y(angle);
}

void ParserController::rotation_z(double angle) {
  parser.result.matrix.rotation_z(angle);
}

void ParserController::move_x(double a) { parser.result.matrix.move_x(a); }

void ParserController::move_y(double a) { parser.result.matrix.move_y(a); }

void ParserController::move_z(double a) { parser.result.matrix.move_z(a); }

void ParserController::scale_x(double k) { parser.result.matrix.scale_x(k); }

void ParserController::scale_y(double k) { parser.result.matrix.scale_y(k); }

void ParserController::scale_z(double k) { parser.result.matrix.scale_z(k); }

void ParserController::scale_xyz(double k) {
  parser.result.matrix.scale_xyz(k);
}

/**
 * @brief get the created model
 * @return the model is Model type
 */
Model ParserController::getModel() { return parser.result; }
