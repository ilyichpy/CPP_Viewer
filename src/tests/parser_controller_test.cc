#include <gtest/gtest.h>

#include <string>

#include "../controller/s21_parser_controller.h"
#include "../model/matrix/s21_matrix_oop.h"
#include "../model/s21_parser.h"

using namespace s21;

// string path = "../cow.obj";
std::string path = "/home/ub/projects/CPP4_3DViewer_v2.0-1/src/cube.obj";
// string path = "/home/ub/projects/CPP4_3DViewer_v2.0-1/src/cow.obj";

TEST(Controller, parser_controller_test_1) {
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

  ParserController pc;
  pc.makeModel(path);
  pc.cleanModel();
  EXPECT_EQ(pc.getModel().matrix.GetRows(), 0);
  EXPECT_EQ(pc.getModel().matrix.GetCols(), 0);
  pc.makeModel(path);
  EXPECT_EQ(pc.getModel().matrix.GetRows(), 8);
  EXPECT_EQ(pc.getModel().matrix.GetCols(), 3);
  EXPECT_EQ(pc.getModel().matrix.EqMatrix(exp.matrix), true);
  pc.parser.remove_parser();
}
