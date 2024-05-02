#include "arrayA.h"
#ifdef _WIN32
#define CLEAR "cls"
#else // In any other OS
#define CLEAR "clear"
#endif
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int pause;
  int op;
  ArrayA alumnos(100);
  char code[10], name[20];
  int n1, n2;
  system(CLEAR);
  do {
    // system(CLEAR);
    cout << "SISTEMA DE REGISTRO DE ALUMNOS" << endl;
    cout << "1. Registrar alumno" << endl;
    cout << "2. Mostrar alumnos" << endl;
    cout << "3. Buscar alumno" << endl;
    cout << "4. Eliminar alumno" << endl;
    cout << "5. Salir" << endl;
    cin >> op;
    switch (op) {
    case 1:
      cout << "Ingrese el codigo del alumno: ";
      cin >> code;
      cout << "Ingrese el nombre del alumno: ";
      cin >> name;
      cout << "Ingrese la nota 1: ";
      cin >> n1;
      cout << "Ingrese la nota 2: ";
      cin >> n2;
      alumnos.add(code, name, n1, n2);
      break;
    case 2:
      alumnos.display();
      // pause = getchar();
      break;
    case 3: {
      cout << "Ingrese el codigo del alumno: ";
      cin >> code;
      int pos = alumnos.search(code);
      if (pos >= 0) {
        alumnos.display(pos);
        // pause = getchar();
      } else {
        cout << "El codigo no existe" << endl;
      }
      break;
    }
    case 4:
      cout << "Ingrese el codigo del alumno: ";
      cin >> code;
      alumnos.remove(code);
      break;
    case 5:
      op = 5;
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
  } while (op != 5);
  return 0;
}
