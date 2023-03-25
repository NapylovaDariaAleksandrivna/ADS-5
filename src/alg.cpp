// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char c) {
    switch (c) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    }
    return -1;
}

std::string infx2pstfx(std::string inf) {
  // добавьте код
  return std::string("");
}

int eval(std::string pref) {
  // добавьте код
  return 0;
}
