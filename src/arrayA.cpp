#include "arrayA.h"
#include <bits/stdc++.h>

using namespace std;

ArrayA::ArrayA(int max) {
  this->max = max;
  this->size = 0;
  this->array = new alumno[max];
}

void ArrayA::add(char code[], char name[], float n1, float n2) {
  if (size < max) {
    int pos;
    pos = this->search(code);
    if (pos <= 0) {
      if (pos != 0) {
        pos = -pos - 1;
      }
      for (int i = size; i > pos; i--) {
        array[i] = array[i - 1];
      }
      strcpy(array[pos].code, code);
      strcpy(array[pos].name, name);
      array[pos].n1 = n1;
      array[pos].n2 = n2;
      array[pos].prom = (n1 + n2) / 2;
      size++;
    } else {
      cout << "El codigo ya existe" << endl;
    }
  } else {
    cout << "El arreglo ya esta lleno";
  }
}

void ArrayA::remove(char code[]) {
  if (size > 0) {
    int pos = search(code);
    if (pos >= 0) {
      size--;
      for (int i = pos; i < size; i++) {
        array[i] = array[i + 1];
      }
    } else {
      cout << "El codigo no existe" << endl;
    }
  } else {
    cout << "El arreglo esta vacio" << endl;
  }
}

void ArrayA::modify(char code[]) {
  int pos = search(code);
  int op;
  if (pos >= 0) {
    cout << "Que desea modificar?" << endl;
    cout << "0. Codigo" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Nota 1" << endl;
    cout << "3. Nota 2" << endl;
    cout << "4. Salir" << endl;
    switch (op) {
    case 0: {
      bool swap = false;
      char newCode[10];
      cout << "Ingrese el nuevo codigo" << endl;
      cin >> newCode;
      int newPos = search(newCode);
      if (newPos >= 0) {
        cout << "El codigo ya existe" << endl;
        break;
      }
      strcpy(array[pos].code, newCode);
      for (int i = 0; i < size; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
          if (atoi(array[j].code) > atoi(array[j + 1].code)) {
            alumno temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
            swapped = true;
          }
        }
        if (!swapped) {
          break;
        }
      }
      break;
    }
    case 1:
      cout << "Ingrese el nuevo nombre" << endl;
      cin >> array[pos].name;
      break;
    case 2:
      cout << "Ingrese la nueva nota 1" << endl;
      cin >> array[pos].n1;
      break;
    case 3:
      cout << "Ingrese la nueva nota 2" << endl;
      cin >> array[pos].n2;
      break;
    case 4:
      break;
    default:
      break;
    }
  } else {
    cout << "El codigo no existe" << endl;
  }
}

int ArrayA::search(char code[]) {
  int d = atoi(code);
  int i = 0;
  while (i < size && atoi(array[i].code) < d) {
    i++;
  }
  if (i >= size || atoi(array[i].code) > d) {
    return -i - 1;
  } else {
    return i;
  }
}

void ArrayA::display() {
  for (int i = 0; i < size; i++) {
    cout << "Codigo: " << array[i].code << endl;
    cout << "Nombre: " << array[i].name << endl;
    cout << "Nota 1: " << array[i].n1 << endl;
    cout << "Nota 2: " << array[i].n2 << endl;
    cout << "Promedio: " << array[i].prom << endl;
    cout << "------------------------------------" << endl;
  }
  cin.get();
}

void ArrayA::display(int pos) {
  cout << "Codigo: " << array[pos].code << endl;
  cout << "Nombre: " << array[pos].name << endl;
  cout << "Nota 1: " << array[pos].n1 << endl;
  cout << "Nota 2: " << array[pos].n2 << endl;
  cout << "Promedio: " << array[pos].prom << endl;
  cout << "------------------------------------" << endl;
  cin.get();
}
