#include "arrayA.h"
#include <cstdlib>
#include <vector>
#ifdef _WIN32
#define CLEAR "cls"
#else // para unix
#define CLEAR "clear"
#endif

#include "ftxui/component/captured_mouse.hpp"     // for ftxui
#include "ftxui/component/component.hpp"          // for Menu
#include "ftxui/component/component_options.hpp"  // for MenuOption
#include "ftxui/component/screen_interactive.hpp" // for ScreenInteractive
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  auto screen = ftxui::ScreenInteractive::Fullscreen();

  int op = 0;
  ArrayA alumnos(100);
  char code[10], name[20];
  int n1, n2;

  vector<string> options = {
      "1. Registrar alumno", "2. Mostrar alumnos", "3. Buscar alumno",
      "4. Eliminar alumno",  "5. Salir",
  };

  ftxui::MenuOption option;
  option.on_enter = screen.ExitLoopClosure();
  auto menu = ftxui::Menu(&options, &op, option);

  system(CLEAR);
  screen.Loop(menu);

  do {
    // system(CLEAR);
    // cout << "SISTEMA DE REGISTRO DE ALUMNOS" << endl;
    // cout << "1. Registrar alumno" << endl;
    // cout << "2. Mostrar alumnos" << endl;
    // cout << "3. Buscar alumno" << endl;
    // cout << "4. Eliminar alumno" << endl;
    // cout << "5. Salir" << endl;
    // cin >> op;
    switch (op) {
    case 0:
      cout << "Ingrese el codigo del alumno: ";
      cin >> code;
      cout << "Ingrese el nombre del alumno: ";
      cin >> name;
      cout << "Ingrese la nota 1: ";
      cin >> n1;
      cout << "Ingrese la nota 2: ";
      cin >> n2;
      alumnos.add(code, name, n1, n2);
      system(CLEAR);
      screen.Loop(menu);
      break;
    case 1:
      alumnos.display();
      cin.get();
      system(CLEAR);
      screen.Loop(menu);
      break;
    case 2: {
      cout << "Ingrese el codigo del alumno: ";
      cin >> code;
      int pos = alumnos.search(code);
      if (pos >= 0) {
        alumnos.display(pos);
      } else {
        cout << "El codigo no existe" << endl;
      }
      system(CLEAR);
      screen.Loop(menu);
      break;
    }
    case 3:
      cout << "Ingrese el codigo del alumno: ";
      cin >> code;
      alumnos.remove(code);
      system(CLEAR);
      screen.Loop(menu);
      break;
    case 4:
      screen.ExitLoopClosure();
      break;
    default:
      cout << "Opcion invalida" << endl;
      break;
    }
  } while (op != 4);
  return 0;
}
