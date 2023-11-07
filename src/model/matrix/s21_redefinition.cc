#include "s21_matrix_oop.h"

double& S21Matrix::operator()(int row, int col) {
  if (rows_ <= row || cols_ <= col || row < 0 || col < 0) {
    throw "ERROR";
  }
  return matrix_[row][col];
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double number) {
  S21Matrix res(*this);
  res.MulNumber(number);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  bool res = this->EqMatrix(other);
  return res;
}

void S21Matrix::operator=(const S21Matrix& other) {
  this->~S21Matrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->MemoryAllocation();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::operator+=(const S21Matrix& other) { this->SumMatrix(other); }

void S21Matrix::operator-=(const S21Matrix& other) { this->SubMatrix(other); }

void S21Matrix::operator*=(const S21Matrix& other) { this->MulMatrix(other); }

void S21Matrix::operator*=(double number) { this->MulNumber(number); }
