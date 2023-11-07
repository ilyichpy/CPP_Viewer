#ifndef S21_MATRIX_PLUS
#define S21_MATRIX_PLUS

#include <cmath>
#include <iostream>

#define DEFAULT_ROWS 1  //!< For constructor without arguments
#define DEFAULT_COLS 1

#define EQ true  //!< For function EqMatrix
#define NOTEQ false

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  void MemoryAllocation();
  S21Matrix Minor(int row, int col);

 public:
  int GetRows();
  int GetCols();
  S21Matrix EditRowsAndCols(int rows, int cols);

  S21Matrix();
  S21Matrix(int, int);
  S21Matrix(const S21Matrix& other);
  //&& - rvalue to work with temporary objects
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  double& operator()(int row, int col);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const double number);
  S21Matrix operator*(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  void operator=(const S21Matrix& other);
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(double number);

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

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

  class MatrixIterator {
    friend class S21Matrix;

   public:
    MatrixIterator() : rows_(0), cols_(0), matrix_(nullptr) {}
    MatrixIterator(int rows, int cols, double** matrix)
        : rows_(rows), cols_(cols), matrix_(matrix) {}

    double& operator*() const { return **matrix_; }
    double operator->() const { return **matrix_; }
    MatrixIterator& operator++() {
      if (j < cols_) {
        this->matrix_[i]++;
        j++;
      } else if (i < rows_) {
        this->matrix_++;
        i++;
        j = 0;
      }
      return *this;
    }
    MatrixIterator& operator--() {
      if (j > 0) {
        this->matrix_[i]--;
        j--;
      } else if (i > 0) {
        this->matrix_--;
        i--;
        j = cols_ - 1;
      }
      return *this;
    }
    MatrixIterator operator++(int) {
      MatrixIterator tmp = *this;
      if (j < cols_) {
        tmp.matrix_[i]++;
        j++;
      } else if (i < rows_) {
        tmp.matrix_++;
        i++;
        j = 0;
      }
      return tmp;
    }
    MatrixIterator operator--(int) {
      MatrixIterator tmp = *this;
      if (j > 0) {
        this->matrix_[i]--;
        j--;
      } else if (i > 0) {
        this->matrix_--;
        i--;
        j = cols_ - 1;
      }
      return tmp;
    }
    MatrixIterator operator+(int val) {
      MatrixIterator tmp = *this;
      for (; val >= 0; val--) {
        // if (j < cols_) {
        //   tmp.matrix_[i]++;
        //   j++;
        // } else if (i < rows_) {
        //   tmp.matrix_++;
        //   i++;
        //   j = 0;
        // }
        tmp++;
      }
      return tmp;
    }
    MatrixIterator operator-(const int val) {
      MatrixIterator tmp = *this;
      for (int k = 0; k < val; k++) {
        if (j > 0) {
          this->matrix_[i]--;
          j--;
        } else if (i > 0) {
          this->matrix_--;
          i--;
          j = cols_ - 1;
        }
      }
      return tmp;
    }
    bool operator==(const MatrixIterator& other) const {
      return matrix_ == other.matrix_;
    }
    bool operator!=(const MatrixIterator& other) const {
      return matrix_ != other.matrix_;
    }
    bool operator>(const MatrixIterator& other) const {
      return matrix_ > other.matrix_;
    }
    bool operator>=(const MatrixIterator& other) const {
      return matrix_ >= other.matrix_;
    }
    bool operator<(const MatrixIterator& other) const {
      return matrix_ < other.matrix_;
    }
    bool operator<=(const MatrixIterator& other) const {
      return matrix_ <= other.matrix_;
    }
    MatrixIterator &operator=(MatrixIterator& other) {
      clear();
      rows_ = other.rows_;
      cols_ = other.cols_;
      matrix_ = new double*[rows_];
      for (int i = 0; i < rows_; i++)
        matrix_[i] = new double[cols_];
      for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
          matrix_[i][j] = other.matrix_[i][j];
      return *this;
    }

   private:
    int i = 0, j = 0;
    int rows_, cols_;
    double** matrix_;
    void clear() {
       if (matrix_ != nullptr) {
        for (int i = 0; i < rows_; i++)
          delete[] matrix_[i];
        delete[] matrix_;
        matrix_ = nullptr;
        cols_ = 0;
        rows_ = 0;
      }
    }
  };

  class MatrixConstIterator : MatrixIterator {
    friend class S21Matrix;

   public:
    MatrixConstIterator() : rows_(0), cols_(0), matrix_(nullptr) {}
    MatrixConstIterator(int rows, int cols, double** matrix)
        : rows_(rows), cols_(cols), matrix_(matrix) {}

    double& operator*() const { return **matrix_; }
    double operator->() const { return **matrix_; }
    MatrixConstIterator& operator++() {
      if (j < cols_) {
        this->matrix_[i]++;
        j++;
      } else if (i < rows_) {
        this->matrix_++;
        i++;
        j = 0;
      }
      return *this;
    }
    MatrixConstIterator& operator--() {
      if (j > 0) {
        this->matrix_[i]--;
        j--;
      } else if (i > 0) {
        this->matrix_--;
        i--;
        j = cols_ - 1;
      }
      return *this;
    }
    MatrixConstIterator operator++(int) {
      MatrixConstIterator tmp = *this;
      if (j < cols_) {
        this->matrix_[i]++;
        j++;
      } else if (i < rows_) {
        this->matrix_++;
        i++;
        j = 0;
      }
      return tmp;
    }
    MatrixConstIterator operator--(int) {
      MatrixConstIterator tmp = *this;
      if (j > 0) {
        this->matrix_[i]--;
        j--;
      } else if (i > 0) {
        this->matrix_--;
        i--;
        j = cols_ - 1;
      }
      return tmp;
    }
    MatrixConstIterator operator+(const int val) {
      MatrixConstIterator tmp = *this;
      for (int k = 0; k < val; k++) {
        if (j < cols_) {
          tmp.matrix_[i]++;
          j++;
        } else if (i < rows_) {
          tmp.matrix_++;
          i++;
          j = 0;
        }
        std::cout << **tmp.matrix_ << std::endl;
      }
      return tmp;
    }
    MatrixConstIterator operator-(const int val) {
      MatrixConstIterator tmp = *this;
      for (int k = 0; k < val; k++) {
        if (j > 0) {
          this->matrix_[i]--;
          j--;
        } else if (i > 0) {
          this->matrix_--;
          i--;
          j = cols_ - 1;
        }
      }
      matrix_ += val / rows_;
      *matrix_ += val % cols_;
      return tmp;
    }

   private:
    int i = 0, j = 0;
    int rows_, cols_;
    double** matrix_;
  };

  using iterator = MatrixIterator;
  using const_iterator = MatrixConstIterator;

  iterator begin() { return iterator(rows_, cols_, matrix_); }
  iterator end() { return iterator(rows_, cols_, matrix_) + (rows_ + cols_); }
  const_iterator cbegin() { return const_iterator(rows_, cols_, matrix_); }
  const_iterator cend() {
    return const_iterator(rows_, cols_, matrix_) + (rows_ + cols_);
  }
};

#endif  // S21_MATRIX_PLUS
