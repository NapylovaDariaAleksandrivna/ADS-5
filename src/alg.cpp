// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char symbol) {
   switch (symbol) {
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
  TStack<char, 100> stack;
  std::string output = "";
  int prior=0;
  int priorOnHeight = -1;
  for (auto& op : inf) {
    prior = getPrior (op);
    priorOnHeight = getPrior (stack.get());
    if (op == '\n') { /* 1. Esli konets stroki*/
      while (getPrior (stack.get())>1) {
        output += stack.pop();
        output += " ";
      }
      stack.pop();
    }
    if (prior == -1) { /* 2. Esli chislo*/
      output += op;
      output += " ";
    } else if (prior == 0){ /* 3. Skobka ( */
      stack.push(op);
    } else if (prior == 1) { /* 4. Esli )*/
      while (getPrior (stack.get())>0) {
       output += stack.pop();
       output += " ";
      }
      stack.pop();
    } else if (prior > priorOnHeight || stack.isEmpty()) {
      stack.push(op);
    } else if (prior <= priorOnHeight && prior > 1) {
      while (getPrior (stack.get())>1) {
        output += stack.pop();
        output += " ";
      }
      stack.push(op);
    }
  }
  while (getPrior (stack.get())>1) {
      output += stack.pop();
      output += " ";
  }
  return output;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
}
