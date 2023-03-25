// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T arr[100];
    int top;

 public:
    TStack() :top(-1) {} 
    void push(T value) {
      if (isFull()) {
        throw std::string("Full");
      } else {
        arr[++top] = value;
      }
    }
    const T& pop() {
      if (isEmpty()) {
        throw std::string("Eempty");
      } else {
        return arr[top--];
      }
    }
    bool isEmpty()const {
      return top == -1;
    }
    int isOne()const {
      return top == 0;
    }
    bool isFull()const {
      return top == size - 1;
    }
    const T& get()const {
      return arr[top];
    }
};

#endif  // INCLUDE_TSTACK_H_
