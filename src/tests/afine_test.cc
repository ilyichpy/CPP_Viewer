#include <gtest/gtest.h>

#include <string>

#include "../model/matrix/s21_matrix_oop.h"
#include "../model/s21_parser.h"

using namespace s21;

// string file_name =
// string file_name = "../cube.obj";
// "/Users/ilazuev/Desktop/CPP4_3DViewer_v2.0-1/src/cube.obj"; string file_name
// string file_name = "/Users/jupitere/CPP4_3DViewer_v2.0-1/src/cube.obj";
std::string file_name = "/home/ub/projects/CPP4_3DViewer_v2.0-1/src/cube.obj";

TEST(afine, test_data_1) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;
  exp.matrix(0, 0) = 1;
  exp.matrix(0, 1) = -1;
  exp.matrix(0, 2) = -1;
  exp.matrix(1, 0) = 1;
  exp.matrix(1, 1) = -1;
  exp.matrix(1, 2) = 1;

  exp.matrix(2, 0) = -1;
  exp.matrix(2, 1) = -1;
  exp.matrix(2, 2) = 1;

  exp.matrix(3, 0) = -1;
  exp.matrix(3, 1) = -1;
  exp.matrix(3, 2) = -1;

  exp.matrix(4, 0) = 1;
  exp.matrix(4, 1) = 1;
  exp.matrix(4, 2) = -1;

  exp.matrix(5, 0) = 1;
  exp.matrix(5, 1) = 1;
  exp.matrix(5, 2) = 1;

  exp.matrix(6, 0) = -1;
  exp.matrix(6, 1) = 1;
  exp.matrix(6, 2) = 1;

  exp.matrix(7, 0) = -1;
  exp.matrix(7, 1) = 1;
  exp.matrix(7, 2) = -1;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_move_x) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 2.0;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 2.0;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = 0.0;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = 0.0;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 2.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 1.999999;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(4, 0) = 2.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -1;

  exp.matrix(5, 0) = 2;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1;

  exp.matrix(6, 0) = 0.0;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = 0.0;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.move_x(1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_move_y) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = 0.0;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = 0.0;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = 0.0;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = 0.0;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 2.0;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 2.0;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 2.0;
  exp.matrix(4, 2) = -1;

  exp.matrix(5, 0) = 1;
  exp.matrix(5, 1) = 2.0;
  exp.matrix(5, 2) = 1;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 2.0;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 2.0;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.move_y(1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_move_z) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = 0.0;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 2.0;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 2.0;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = 0.0;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = 0.000001;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 2.000001;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = 0;

  exp.matrix(5, 0) = 1;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 2;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = 0;

  exp.matrix(5, 0) = 1;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 2;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 2.0;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = 0.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.move_z(1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_scale_xyz) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0 * 2;
  exp.matrix(0, 1) = -1.0 * 2;
  exp.matrix(0, 2) = -1.0 * 2;

  exp.matrix(1, 0) = 1.0 * 2;
  exp.matrix(1, 1) = -1.0 * 2;
  exp.matrix(1, 2) = 1.0 * 2;

  exp.matrix(2, 0) = -1.0 * 2;
  exp.matrix(2, 1) = -1.0 * 2;
  exp.matrix(2, 2) = 1.0 * 2;

  exp.matrix(3, 0) = -1.0 * 2;
  exp.matrix(3, 1) = -1.0 * 2;
  exp.matrix(3, 2) = -1.0 * 2;

  exp.matrix(4, 0) = 1.0 * 2;
  exp.matrix(4, 1) = 1.0 * 2;
  exp.matrix(4, 2) = -0.999999 * 2;

  exp.matrix(5, 0) = 0.999999 * 2;
  exp.matrix(5, 1) = 1.0 * 2;
  exp.matrix(5, 2) = 1.000001 * 2;

  exp.matrix(4, 0) = 1.0 * 2;
  exp.matrix(4, 1) = 1.0 * 2;
  exp.matrix(4, 2) = -1 * 2;

  exp.matrix(5, 0) = 1 * 2;
  exp.matrix(5, 1) = 1.0 * 2;
  exp.matrix(5, 2) = 1 * 2;

  exp.matrix(6, 0) = -1.0 * 2;
  exp.matrix(6, 1) = 1.0 * 2;
  exp.matrix(6, 2) = 1.0 * 2;

  exp.matrix(7, 0) = -1.0 * 2;
  exp.matrix(7, 1) = 1.0 * 2;
  exp.matrix(7, 2) = -1.0 * 2;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.scale_xyz(2.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_rotation_x) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = -0.366025;
  exp.matrix(0, 2) = -1.366025;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = -1.366025;
  exp.matrix(1, 2) = 0.366025;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = -1.366025;
  exp.matrix(2, 2) = 0.366025;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = -0.366025;
  exp.matrix(3, 2) = -1.366025;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.366025;
  exp.matrix(4, 2) = -0.366025;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 0.366025;
  exp.matrix(5, 2) = 1.366026;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 0.366025;
  exp.matrix(6, 2) = 1.366025;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 1.366025;
  exp.matrix(7, 2) = -0.366025;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.rotation_x(1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_rotation_y) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.366025;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = -0.366025;

  exp.matrix(1, 0) = 0.366025;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 1.366025;

  exp.matrix(2, 0) = -1.366025;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 0.366025;

  exp.matrix(3, 0) = -0.366025;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = -1.366025;

  exp.matrix(4, 0) = 1.366025;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -0.366025;

  exp.matrix(5, 0) = 0.366025;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1.366025;

  exp.matrix(6, 0) = -1.366025;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 0.366025;

  exp.matrix(7, 0) = -0.366025;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = -1.366025;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.rotation_y(1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_rotation_z) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.366025;
  exp.matrix(0, 1) = -0.366025;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 1.366025;
  exp.matrix(1, 1) = -0.366025;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = -0.366025;
  exp.matrix(2, 1) = -1.366025;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = -0.366025;
  exp.matrix(3, 1) = -1.366025;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 0.366025;
  exp.matrix(4, 1) = 1.366025;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 0.366025;
  exp.matrix(5, 1) = 1.366025;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(6, 0) = -1.366025;
  exp.matrix(6, 1) = 0.366025;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = -1.366025;
  exp.matrix(7, 1) = 0.366025;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.rotation_z(1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_scale_x_1) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.scale_x(1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_scale_x_2) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.scale_x(-1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_scale_y_1) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.scale_y(1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_scale_y_2) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.scale_y(-1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_scale_z_1) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.scale_z(1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_scale_z_2) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.scale_z(-1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}

TEST(afine, test_scale_xyz_2) {
  Model exp;
  exp.count_of_facets = 8;
  exp.count_of_vertexes = 12;
  exp.matrix = S21Matrix(8, 3);
  exp.status = OK;

  exp.count_of_vertexes = 36;

  exp.matrix(0, 0) = 1.0;
  exp.matrix(0, 1) = -1.0;
  exp.matrix(0, 2) = -1.0;

  exp.matrix(1, 0) = 1.0;
  exp.matrix(1, 1) = -1.0;
  exp.matrix(1, 2) = 1.0;

  exp.matrix(2, 0) = -1.0;
  exp.matrix(2, 1) = -1.0;
  exp.matrix(2, 2) = 1.0;

  exp.matrix(3, 0) = -1.0;
  exp.matrix(3, 1) = -1.0;
  exp.matrix(3, 2) = -1.0;

  exp.matrix(4, 0) = 1.0;
  exp.matrix(4, 1) = 1.0;
  exp.matrix(4, 2) = -0.999999;

  exp.matrix(5, 0) = 0.999999;
  exp.matrix(5, 1) = 1.0;
  exp.matrix(5, 2) = 1.000001;

  exp.matrix(6, 0) = -1.0;
  exp.matrix(6, 1) = 1.0;
  exp.matrix(6, 2) = 1.0;

  exp.matrix(7, 0) = -1.0;
  exp.matrix(7, 1) = 1.0;
  exp.matrix(7, 2) = -1.0;

  Parser &parser = Parser::getInstance();
  parser.start(file_name);
  parser.result.matrix.scale_xyz(-1.0);

  EXPECT_EQ(parser.result.matrix.GetRows(), 8);
  EXPECT_EQ(parser.result.matrix.GetCols(), 3);
  EXPECT_EQ(parser.result.matrix.EqMatrix(exp.matrix), true);
  parser.remove_parser();
}
