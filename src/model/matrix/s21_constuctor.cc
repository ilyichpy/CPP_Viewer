#include "s21_matrix_oop.h"

int S21Matrix::GetRows() { return rows_; }  //<! access to private field: rows_
int S21Matrix::GetCols() { return cols_; }  //<! access to private field: cols_

S21Matrix S21Matrix::EditRowsAndCols(int rows, int cols) {
  if (cols < 0 || cols < 0) {
    throw "ERROR";
  }
  S21Matrix new_matrix = S21Matrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i >= rows_ || j >= cols_) {
        new_matrix.matrix_[i][j] = 0;
      } else {
        new_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  return new_matrix;
}

/**
 * If in this constructor we dont't get arguments then we craft default
 * matrix with size 1x1
 */
S21Matrix::S21Matrix() : S21Matrix(DEFAULT_ROWS, DEFAULT_COLS) {
  // std::cout << "матрица 1 х 1" << this << std::endl;
}

/**
 * Create matrix with size rows x cols
 * If rows or cols have incorrect size, we will get error
 */
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw "ERROR";
  }
  rows_ = rows;
  cols_ = cols;
  this->MemoryAllocation();
  // std::cout << "матрица rowsXcols" << this << std::endl;
}

/**
 * This is constructor which copy all fields of "other" to new object of class
 * S21Matrix "this"
 *
 * We must make object and allocate memory in other place then object "other"
 * otherwise we can get error from destructor
 */
S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->MemoryAllocation();
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  // std::cout << "матрица копирования" << this << std::endl;
}

/**
 *  This constructor move fields from "other" to "this" and then remove object
 * "other"
 *
 * We init fields of "this" by fields of "other"
 *  */
S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.cols_ = 0;
  other.rows_ = 0;
  other.matrix_ = nullptr;
  // std::cout << "матрица перемещения" << this << std::endl;
}

/**
 * destructor clear memory and fields in class S21Matrix
 */
S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
  // std::cout << "деструктор" << this << std::endl;
}

/**
 * Allocation memory for matrix
 */
void S21Matrix::MemoryAllocation() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}
