#include <gtest/gtest.h>

#include "../model/matrix/s21_matrix_oop.h"

// contructors**************************************************
/**
 * There are included 2 types of test
 * - Check rows and cols
 * - catch error when we try to change inaccessible matrix values
 */

TEST(Constructors_test, simple1x1) {
  S21Matrix test_ = S21Matrix();
  test_(0, 0) = 2.5;
  ASSERT_EQ(test_(0, 0), 2.5);
  ASSERT_EQ(test_.GetRows(), 1);
  ASSERT_EQ(test_.GetCols(), 1);
  try {
    test_(-2, 0) = 3;
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* error_message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
  try {
    test_(1, 0) = 2;
    int err_code = 0;
    ASSERT_EQ(err_code, 1);  // Don `t come in
  } catch (const char* error_message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}

TEST(Constructors_test, rowsXcols) {
  S21Matrix test_1(2, 5);
  double checkValue_ = 0.0;
  ASSERT_EQ(test_1.GetRows(), 2);
  ASSERT_EQ(test_1.GetCols(), 5);
  for (int i = 0; i < test_1.GetRows(); i++) {
    for (int j = 0; j < test_1.GetCols(); j++) {
      checkValue_ = j * 0.2 + 2;
      test_1(i, j) = checkValue_;
      ASSERT_EQ(test_1(i, j), checkValue_);
    }
  }
  try {
    test_1(-23, 21) = 2.6;
    int err_code = 0;
    ASSERT_EQ(err_code, 1);  // Don `t come in
  } catch (const char* error_message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
  try {
    test_1(123, 12) = 12312.23;
    int err_code = 0;
    ASSERT_EQ(err_code, 1);  // Don `t come in
  } catch (const char* error_message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
  S21Matrix test_2(1000, 999);
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      checkValue_ = j / 5 - 2;
      test_2(i, j) = checkValue_;
      ASSERT_EQ(test_2(i, j), checkValue_);
    }
  }
}

TEST(Constructors_test, CopyConstuctor) {
  S21Matrix test_(100, 50);
  double checkValue_ = 0.0;
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      checkValue_ = j * 0.2 + 2;
      test_(i, j) = checkValue_;
      ASSERT_EQ(test_(i, j), checkValue_);
    }
  }
  S21Matrix test_1 = S21Matrix(test_);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      ASSERT_EQ(test_(i, j), test_1(i, j));
    }
  }
  S21Matrix test_3(500, 973);
  for (int i = 0; i < test_3.GetRows(); i++) {
    for (int j = 0; j < test_3.GetCols(); j++) {
      checkValue_ = j * 18.9123;
      test_3(i, j) = checkValue_;
      ASSERT_EQ(test_3(i, j), checkValue_);
    }
  }
  S21Matrix test_4 = S21Matrix(test_3);
  for (int i = 0; i < test_4.GetRows(); i++) {
    for (int j = 0; j < test_4.GetCols(); j++) {
      ASSERT_EQ(test_3(i, j), test_4(i, j));
    }
  }
}

TEST(Constructors_test, MoveConstructor) {
  S21Matrix from_(5, 5);
  for (int i = 0; i < from_.GetRows(); i++) {
    for (int j = 0; j < from_.GetCols(); j++) {
      from_(i, j) = j;
    }
  }
  S21Matrix to_ = std::move(from_);
  for (int i = 0; i < to_.GetRows(); i++) {
    for (int j = 0; j < to_.GetCols(); j++) {
      ASSERT_EQ(to_(i, j), j);
    }
  }
  try {
    from_(1, 1);
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}
// END contructors**************************************************
// operations*******************************************************

TEST(Operation_test, EqMatix) {
  S21Matrix test_(1000, 1000);
  double checkValue_ = 0.0;
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      checkValue_ = j * 0.2 + 2;
      test_(i, j) = checkValue_;
    }
  }
  S21Matrix test_2 = S21Matrix(test_);
  bool eq_ = test_.EqMatrix(test_2);
  ASSERT_EQ(eq_, true);
  test_2(4, 2) = 5;
  eq_ = test_.EqMatrix(test_2);
  ASSERT_EQ(eq_, false);
}

TEST(Operation_test, SumMatrix) {
  S21Matrix test_(5, 10);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = j;
    }
  }
  S21Matrix test_2 = S21Matrix(test_);
  test_2.SumMatrix(test_);
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      ASSERT_EQ(test_2(i, j), j * 2);
    }
  }
  test_2.SumMatrix(test_2);
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      ASSERT_EQ(test_2(i, j), j * 4);
    }
  }
  S21Matrix test_3(5, 10);
  test_3.SumMatrix(test_2);
  bool eq_ = test_3.EqMatrix(test_2);
  ASSERT_EQ(eq_, true);
  S21Matrix error_(10, 10);
  try {
    error_.SumMatrix(test_3);
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}

TEST(Operation_test, SubMatrix) {
  S21Matrix test_(5, 10);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = j;
    }
  }
  S21Matrix test_2(test_);
  test_2.SubMatrix(test_);
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      ASSERT_EQ(test_2(i, j), 0);
    }
  }
  test_2.SubMatrix(test_);
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      ASSERT_EQ(test_2(i, j), -j);
    }
  }
  S21Matrix test_3(5, 10);
  test_3.SubMatrix(test_2);
  for (int i = 0; i < test_3.GetRows(); i++) {
    for (int j = 0; j < test_3.GetCols(); j++) {
      ASSERT_EQ(test_3(i, j), -test_2(i, j));
    }
  }
  S21Matrix error_(10, 10);
  try {
    error_.SumMatrix(test_3);
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}

TEST(Operation_test, MultNumber) {
  S21Matrix test_(100, 100);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = i * 15;
    }
  }
  test_.MulNumber(13.32);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      ASSERT_EQ(test_(i, j), i * 15 * 13.32);
    }
  }
  test_.MulNumber(-0.2);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      ASSERT_EQ(test_(i, j), i * 15 * 13.32 * (-0.2));
    }
  }
}

TEST(Operation_test, MultMatrix) {
  S21Matrix test_(3, 3);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = j * 12.5;
    }
  }
  S21Matrix test_2(3, 3);
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      test_2(i, j) = j * 9;
    }
  }
  test_.MulMatrix(test_2);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      ASSERT_EQ(test_(i, j), j * 337.5);
    }
  }
  S21Matrix test_3 = S21Matrix(1, 2);
  S21Matrix test_4(2, 1);
  for (int i = 0; i < test_3.GetRows(); i++) {
    for (int j = 0; j < test_3.GetCols(); j++) {
      test_3(i, j) = (j + 1) * 2;
    }
  }
  for (int i = 0; i < test_4.GetRows(); i++) {
    for (int j = 0; j < test_4.GetCols(); j++) {
      test_4(i, j) = (j + 1) * 2;
    }
  }
  test_3.MulMatrix(test_4);
  ASSERT_EQ(test_3(0, 0), 12);
  S21Matrix test_5(1, 2);
  for (int i = 0; i < test_5.GetRows(); i++) {
    for (int j = 0; j < test_5.GetCols(); j++) {
      test_5(i, j) = (j + 1) * 2;
    }
  }
  test_4.MulMatrix(test_5);
  ASSERT_EQ(test_4(0, 0), 4);
  ASSERT_EQ(test_4(0, 1), 8);
  ASSERT_EQ(test_4(1, 0), 4);
  ASSERT_EQ(test_4(1, 1), 8);

  S21Matrix test_6(240, 59);
  S21Matrix test_7(59, 123);
  for (int i = 0; i < test_6.GetRows(); i++) {
    for (int j = 0; j < test_6.GetCols(); j++) {
      test_6(i, j) = j;
    }
  }
  for (int i = 0; i < test_7.GetRows(); i++) {
    for (int j = 0; j < test_7.GetCols(); j++) {
      test_7(i, j) = j;
    }
  }
  test_6.MulMatrix(test_7);
  ASSERT_EQ(test_6(0, 100), 171100);
  try {
    test_7.MulMatrix(test_6);
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}

TEST(Operation_test, Trancpose) {
  S21Matrix test_(3, 3);
  S21Matrix test_2 = S21Matrix(test_);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = j + 1;
      test_2(i, j) = j + 1;
    }
  }
  test_ = test_2.Transpose();
  ASSERT_EQ(test_2.GetRows(), 3);
  ASSERT_EQ(test_2.GetCols(), 3);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      ASSERT_EQ(test_(j, i), test_2(i, j));
    }
  }
  S21Matrix test_3(400, 800);
  S21Matrix test_4 = test_3.Transpose();
  ASSERT_EQ(test_4.GetRows(), 800);
  ASSERT_EQ(test_4.GetCols(), 400);
}

TEST(Operation_test, CalcComplements) {
  double matrix[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double result[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  S21Matrix test_(3, 3);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = matrix[i][j];
    }
  }
  S21Matrix check_ = test_.CalcComplements();
  for (int i = 0; i < check_.GetRows(); i++) {
    for (int j = 0; j < check_.GetCols(); j++) {
      ASSERT_EQ(check_(i, j), result[i][j]);
    }
  }
  double matrix_2[5][5] = {{6, 2, 7, 2, 3},
                           {9, 2, 3, 6, 2},
                           {9, 8, 1, 1, 1},
                           {1, 8, 2, 2, 7},
                           {-4, 2, -6, 1, 1}};
  double result_2[5][5] = {{1744, -1856, -1648, -2160, 2960},
                           {-584, 626, 548, 684, -984},
                           {152, -194, -148, -188, 296},
                           {-816, 872, 768, 1024, -1424},
                           {1496, -1594, -1380, -1868, 2536}};
  S21Matrix test_2(5, 5);
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      test_2(i, j) = matrix_2[i][j];
    }
  }
  S21Matrix check_2 = test_2.CalcComplements();
  for (int i = 0; i < check_2.GetRows(); i++) {
    for (int j = 0; j < check_2.GetCols(); j++) {
      ASSERT_EQ(check_2(i, j), result_2[i][j]);
    }
  }
  S21Matrix test_3(2, 3);
  try {
    S21Matrix check_3 = test_3.CalcComplements();
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}

TEST(Operation_test, InverseMatrix) {
  double matrix[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double matrix_throw[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  double result[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  S21Matrix test_1(3, 3);
  S21Matrix test_2(3, 3);
  for (int i = 0; i < test_1.GetRows(); i++) {
    for (int j = 0; j < test_1.GetCols(); j++) {
      test_1(i, j) = matrix[i][j];
    }
  }
  S21Matrix result_ = test_1.InverseMatrix();
  for (int i = 0; i < result_.GetRows(); i++) {
    for (int j = 0; j < result_.GetCols(); j++) {
      ASSERT_EQ(result_(i, j), result[i][j]);
    }
  }
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      test_2(i, j) = matrix_throw[i][j];
    }
  }
  try {
    S21Matrix result_2 = test_2.InverseMatrix();
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}
// END operations***************************************************
// redefinition*****************************************************

TEST(Redefinition_test, plusTest) {
  S21Matrix test_(5, 10);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = j;
    }
  }
  S21Matrix test_2(test_);
  S21Matrix result = test_2 + test_;
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      ASSERT_EQ(result(i, j), j * 2);
    }
  }
  S21Matrix result_2 = result + result;
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      ASSERT_EQ(result_2(i, j), j * 4);
    }
  }
  S21Matrix test_3(5, 10);
  test_3 += test_2;
  bool eq_ = test_3.EqMatrix(test_2);
  ASSERT_EQ(eq_, true);
  S21Matrix error_(10, 10);
  try {
    error_ = error_ + test_3;
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}

TEST(Redefinition_test, SubMatrix) {
  S21Matrix test_(5, 10);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = j;
    }
  }
  S21Matrix test_2(test_);
  test_2 = test_2 - test_;
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      ASSERT_EQ(test_2(i, j), 0);
    }
  }
  test_2 -= test_;
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      ASSERT_EQ(test_2(i, j), -j);
    }
  }
  S21Matrix test_3(5, 10);
  test_3 -= test_2;
  for (int i = 0; i < test_3.GetRows(); i++) {
    for (int j = 0; j < test_3.GetCols(); j++) {
      ASSERT_EQ(test_3(i, j), -test_2(i, j));
    }
  }
  S21Matrix error_(10, 10);
  try {
    error_ = error_ - test_3;
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}

TEST(Redefinition_test, MultNumber) {
  S21Matrix test_(100, 100);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = i * 15;
    }
  }
  test_ = test_ * 13.32;
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      ASSERT_EQ(test_(i, j), i * 15 * 13.32);
    }
  }
  test_ *= -0.2;
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      ASSERT_EQ(test_(i, j), i * 15 * 13.32 * (-0.2));
    }
  }
}

TEST(Redefinition_test, MultMatrix) {
  S21Matrix test_(3, 3);
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      test_(i, j) = j * 12.5;
    }
  }
  S21Matrix test_2(3, 3);
  for (int i = 0; i < test_2.GetRows(); i++) {
    for (int j = 0; j < test_2.GetCols(); j++) {
      test_2(i, j) = j * 9;
    }
  }
  test_ = test_ * test_2;
  for (int i = 0; i < test_.GetRows(); i++) {
    for (int j = 0; j < test_.GetCols(); j++) {
      ASSERT_EQ(test_(i, j), j * 337.5);
    }
  }
  S21Matrix test_3(1, 2);
  S21Matrix test_4(2, 1);
  for (int i = 0; i < test_3.GetRows(); i++) {
    for (int j = 0; j < test_3.GetCols(); j++) {
      test_3(i, j) = (j + 1) * 2;
    }
  }
  for (int i = 0; i < test_4.GetRows(); i++) {
    for (int j = 0; j < test_4.GetCols(); j++) {
      test_4(i, j) = (j + 1) * 2;
    }
  }
  test_3 *= test_4;
  ASSERT_EQ(test_3(0, 0), 12);
  S21Matrix test_5(1, 2);
  for (int i = 0; i < test_5.GetRows(); i++) {
    for (int j = 0; j < test_5.GetCols(); j++) {
      test_5(i, j) = (j + 1) * 2;
    }
  }
  S21Matrix test_8 = test_4 * test_5;
  ASSERT_EQ(test_8(0, 0), 4);
  ASSERT_EQ(test_8(0, 1), 8);
  ASSERT_EQ(test_8(1, 0), 4);
  ASSERT_EQ(test_8(1, 1), 8);

  S21Matrix test_6(240, 59);
  S21Matrix test_7(59, 123);
  for (int i = 0; i < test_6.GetRows(); i++) {
    for (int j = 0; j < test_6.GetCols(); j++) {
      test_6(i, j) = j;
    }
  }
  for (int i = 0; i < test_7.GetRows(); i++) {
    for (int j = 0; j < test_7.GetCols(); j++) {
      test_7(i, j) = j;
    }
  }
  test_6 *= test_7;
  ASSERT_EQ(test_6(0, 100), 171100);
  try {
    test_7 = test_7 * test_6;
    int err_code = 0;
    ASSERT_EQ(err_code, 1);
  } catch (const char* message) {
    int err_code = 1;
    ASSERT_EQ(err_code, 1);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
  return result;
}
