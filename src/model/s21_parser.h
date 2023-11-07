#ifndef S21_PARSER_
#define S21_PARSER_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "./matrix/s21_matrix_oop.h"

namespace s21 {
enum Status { EMPTY, OK, OPEN_ERROR };

typedef struct model {
  int count_of_vertexes;
  int count_of_facets;
  S21Matrix matrix;
  int *polygons = nullptr;
  Status status;
} Model;

class Parser {
 public:
  static Parser &getInstance();
  Parser(Parser const &) = delete;
  void operator=(Parser const &other) = delete;
  ~Parser() { remove_parser(); }
  void start(std::string &str);
  Model result;
  void remove_parser();
  void init();

 private:
  Parser() {}
  void first_open(std::string &str);
  void second_open(std::string &str);
  int count_words(std::string &str);
};

}  // namespace s21

#endif  // S21_PARSER_
