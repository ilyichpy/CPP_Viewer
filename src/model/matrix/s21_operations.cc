#include "s21_matrix_oop.h"

/**
 * simple method to understand eq or not eq
 *
 * @details No errors are possible. If user put incorrect info then get error
 *
 * @return[bool] Eq or NotEq
 */
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool equality = EQ;
  if ((cols_ != other.cols_) || (rows_ != other.rows_)) {
    equality = NOTEQ;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (abs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
          equality = NOTEQ;
        }
      }
    }
  }
  return equality;
}

double abs_matrix(double num) { return num < 0 ? num *= -1 : num; }
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw "ERROR";
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw "ERROR";
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw "ERROR1";
  }
  S21Matrix tmp(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < tmp.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        tmp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  this->~S21Matrix();
  cols_ = tmp.cols_;
  rows_ = tmp.rows_;
  MemoryAllocation();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = tmp.matrix_[i][j];
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res.matrix_[j][i] = matrix_[i][j];
    }
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw "ERROR";
  }
  S21Matrix tmp(*this);
  S21Matrix minor_(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      minor_ = this->Minor(i, j);
      double det = minor_.Determinant();
      double sign = pow(-1, i + j);
      tmp.matrix_[i][j] = sign * det;
    }
  }
  return tmp;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw "ERROR";
  }
  double res = 0.0;
  if (rows_ == 1) {
    res = matrix_[0][0];
  } else if (rows_ == 2) {
    res = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      S21Matrix minor = this->Minor(0, i);
      double sign = pow(-1, i);
      double det = minor.Determinant();
      res += matrix_[0][i] * sign * det;
    }
  }
  return res;
}

/**
 * @param[in] row, int, this row which we will pass
 * @param[in] col, int , this col we will pass
 */
S21Matrix S21Matrix::Minor(int row, int col) {
  int RowC = 0, ColC = 0;  //<! There are usual counter for rows_ and cols which
  S21Matrix res = S21Matrix(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    if (i != row) {
      for (int j = 0; j < cols_; j++) {
        if (col != j) {
          res.matrix_[RowC][ColC] = matrix_[i][j];
          ++ColC;
        }
      }
      ColC = 0;
      ++RowC;
    }
  }
  return res;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (fabs(Determinant() - 0.0) < 1e-7) {
    throw "ERROR";
  }
  S21Matrix inverse(CalcComplements());
  inverse = inverse.Transpose();
  if (Determinant()) {
    inverse *= 1 / Determinant();
  }
  return inverse;
}

double S21Matrix::grad_to_rad(double grad) { return grad * M_PI / 180; }

void S21Matrix::rotation_x(double angle) {
  angle = grad_to_rad(angle);
  for (int i = 0; i < rows_; i++) {
    double y = matrix_[i][1];
    double z = matrix_[i][2];
    matrix_[i][1] = cos(angle) * y - sin(angle) * z;
    matrix_[i][2] = sin(angle) * y + cos(angle) * z;
  }
}

void S21Matrix::rotation_y(double angle) {
  angle = grad_to_rad(angle);
  for (int i = 0; i < rows_; i++) {
    double x = matrix_[i][0];
    double z = matrix_[i][2];
    matrix_[i][0] = cos(angle) * x - sin(angle) * z;
    matrix_[i][2] = sin(angle) * x + cos(angle) * z;
  }
}

void S21Matrix::rotation_z(double angle) {
  angle = grad_to_rad(angle);
  for (int i = 0; i < rows_; i++) {
    double x = matrix_[i][0];
    double y = matrix_[i][1];
    matrix_[i][0] = cos(angle) * x - sin(angle) * y;
    matrix_[i][1] = sin(angle) * x + cos(angle) * y;
  }
}

void S21Matrix::move_x(double a) {
  for (int i = 0; i < rows_; i++) {
    matrix_[i][0] += a;
  }
}

void S21Matrix::move_y(double a) {
  for (int i = 0; i < rows_; i++) {
    matrix_[i][1] += a;
  }
}

void S21Matrix::move_z(double a) {
  for (int i = 0; i < rows_; i++) {
    matrix_[i][2] += a;
  }
}

void S21Matrix::scale_x(double k) {
  for (int i = 0; i < rows_; i++) {
    if (k > 0) {
      matrix_[i][0] *= k;
    } else if (k < 0) {
      matrix_[i][0] /= (-1) * k;
    }
  }
}

void S21Matrix::scale_y(double k) {
  for (int i = 0; i < rows_; i++) {
    if (k > 0) {
      matrix_[i][1] *= k;
    } else if (k < 0) {
      matrix_[i][1] /= (-1) * k;
    }
  }
}

void S21Matrix::scale_z(double k) {
  for (int i = 0; i < rows_; i++) {
    if (k > 0) {
      matrix_[i][2] *= k;
    } else if (k < 0) {
      matrix_[i][2] /= (-1) * k;
    }
  }
}

void S21Matrix::scale_xyz(double k) {
  for (int i = 0; i < rows_; i++) {
    if (k > 0) {
      matrix_[i][0] *= k;
      matrix_[i][1] *= k;
      matrix_[i][2] *= k;
    } else if (k < 0) {
      matrix_[i][0] /= -k;
      matrix_[i][1] /= -k;
      matrix_[i][2] /= -k;
    }
  }
}
