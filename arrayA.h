#ifndef ARRAYA_H
#define ARRAYA_H

#include "alumno.h"

class ArrayA {
private:
  int size;
  alumno *array;
  int max;

public:
  ArrayA(int);
  void add(char[], char[], float, float);
  int search(char[]);
  void remove(char[]);
  void modify(char[]);
  void display();
  void display(int);
};

#include "arrayA.cpp"
#endif // !DEBUG
