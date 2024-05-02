#include "arrayA.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  ArrayA alumnos(100);
  char code[] = "1001", name[] = "Juan Perez";
  char code2[] = "10", name2[] = "Maria Lopez";
  char code3[] = "20";

  alumnos.add(code3, name, 12, 13);
  alumnos.add(code2, name, 15, 16);
  alumnos.add(code, name, 12, 13);
  alumnos.display();
  return 0;
}
