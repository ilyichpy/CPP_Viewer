#include "./s21_parser.h"

using namespace s21;

#define V_CONDITION line[0] == 'v' && line[1] == ' '
#define F_CONDITION line[0] == 'f' && line[1] == ' '

/**
 * @brief get the parser object
 * @return [s21::Parser] parser
 */
Parser &Parser::getInstance() {
  static Parser p;
  return p;
}

/**
 * @brief initialize model
 */
void Parser::init() {
  result.count_of_facets = 0;
  result.count_of_vertexes = 0;
  result.polygons = nullptr;
  result.status = OK;
}

/**
 * @brief make magic and fill the data model from the object file
 */
void Parser::start(std::string &str) {
  result.count_of_vertexes = 0;
  result.count_of_facets = 0;
  result.polygons = nullptr;
  result.status = OK;

  if (str.empty()) {
    result.status = EMPTY;
  } else {
    first_open(str);
    second_open(str);
  }
}

/**
 * @brief count vertices and faces and fill their in the model
 * @param [std::string] &str is model path
 */
void Parser::first_open(std::string &str) {
  std::ifstream file(str);

  if (!file.is_open()) {
    result.status = OPEN_ERROR;
  } else {
    std::string line;

    if (V_CONDITION) ++result.count_of_vertexes;
    if (line[0] == 'f') ++result.count_of_facets;

    while (getline(file, line)) {
      if (V_CONDITION) ++result.count_of_vertexes;
      if (line[0] == 'f') ++result.count_of_facets;
    }

    if (!line.empty()) {
      line.clear();
    }
  }

  file.close();
}

/**
 * @brief fill the matrix and poligons model from data file
 * @param [std::string] &str is model path
 */
void Parser::second_open(std::string &str) {
  result.matrix = S21Matrix(result.count_of_vertexes, 3);
  result.polygons = new int[result.count_of_facets * 6];
  std::ifstream file(str);

  if (!file.is_open()) {
    result.status = OPEN_ERROR;
  } else {
    int i = 0, j = 0;
    std::string line;
    std::stringstream ss;

    while (getline(file, line)) {
      ss << line << '\0';
      double num = 0.0;
      if (V_CONDITION) {
        std::string tmp = "";
        int k = 0;
        while (!ss.eof()) {
          ss >> tmp;
          if (std::stringstream(tmp) >> num) {
            result.matrix(i, k) = num;
            k++;
          }
        }
        i++;
      } else if (F_CONDITION) {
        for (size_t s = 2, check = 1; s < line.length(); s++, check++) {
          if (!isdigit(line[s])) continue;
          int num = 0;
          while (isdigit(line[s]) && line[s] != '\n' && s < line.length()) {
            num = num * 10 + (line[s] - '0');
            s++;
          }
          if (check > 1) {
            result.polygons[j++] = num - 1;
          }
          result.polygons[j++] = num - 1;
          if (check == 3) {
            result.polygons[j] = result.polygons[j - 5];
            j++;
          }
          while (line[s] != '\n' && s < line.length() && line[s] != ' ') s++;
        }
      }
      ss.str("");
      ss.clear();
    }
    if (!line.empty()) {
      line.clear();
    }
  }
  file.close();
}

void Parser::remove_parser() {
  if (result.polygons != nullptr) {
    delete[] result.polygons;
    result.polygons = nullptr;
    result.count_of_facets = 0;
    result.count_of_vertexes = 0;
    result.status = OK;
  }
  result.matrix.~S21Matrix();
}
