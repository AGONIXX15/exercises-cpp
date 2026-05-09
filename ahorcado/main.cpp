#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>

void print_try(int tried) {}

void limpiar(std::string &str) {
  for (char &a : str) {
    a = '_';
  }
}

bool comprobar(std::string &oculta, std::string &resultado, char &a) {
  bool flag = false;
  for (int i = 0; i < oculta.size(); ++i) {
    if (oculta[i] == a && resultado[i] == '_') {
      resultado[i] = a;
      flag = true;
    }
  }
  return flag;
}

void game() {
  std::string cadenas[] = {"hola", "python", "c++", "golang"};
  srand((unsigned)time(NULL));
  std::cout << "bienvenido al ahorcado" << '\n';
  int number = (rand()) % 4;
  std::string oculta = cadenas[number];
  std::string resultado = oculta;
  limpiar(resultado);
  while (true) {
    std::cout << resultado << '\n';
    char a;
    std::cout << "ingrese una letra:";
    std::cin >> a;
    if (comprobar(oculta, resultado, a)) {
      std::cout << "intento fue correcto" << '\n';
      std::cout << "cadena hasta ahora:" << resultado << '\n';
    } else {
      std::cout << "intento fue incorrecto" << '\n';
      std::cout << "cadena hasta ahora:" << resultado << '\n';
    }
    if (oculta == resultado) {
      break;
    }
  }
}

bool comprobar(std::unordered_map<int, bool> &dct) {
  bool flag = true;
  for (const auto& it: dct) {
    if (!it.second) {
      flag = false;
    }
  }
  return flag;
}

bool comprobar2(int number, int min, int max) {
  if (number >= min && number <= max) {
    return true;
  }
  return false;
}

int select_row() {
  int row;
  do {
    std::cout << "selecciona una fila (1-2):";
    std::cin >> row;
    if (!comprobar2(row, 1, 2)) {
      std::cout << "fila out of bounds" << '\n';
      continue;
    }
    break;
  } while (true);
  return row;
}
int select_col() {
  int col;
  do {
    std::cout << "seleccione una columna (1-5):";
    std::cin >> col;
    if (!comprobar2(col, 1, 5)) {
      std::cout << "column out of bounds" << '\n';
      continue;
    }
    break;
  } while (true);
  return col;
}

int select(int (&array)[2][5], int row, int col) {
  return array[row - 1][col - 1];
}

void print_state(char (&result)[2][5]) {

  for (int i = 0; i < 2; ++i) {
    std::cout << '[';
    for (int j = 0; j < 5; ++j) {
      if (j == 4) {
        std::cout << result[i][j];
      } else {
        std::cout << result[i][j] << ", ";
      }
    }
    std::cout << ']' << '\n';
  }
}

void game2() {
  int array[2][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
  std::unordered_map<int, bool> dct = {{1,false}, {2,false}, {3, false}, {4, false}, {5, false}};
  char result[2][5];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      result[i][j] = '_';
    }
  }
  while (true) {
    print_state(result);
    std::cout << "seleccione el primer numero:\n";
    int row1 = select_row();
    int col1 = select_col();
    int number1 = select(array, row1,col1);
    result[row1-1][col1-1] = 48 + number1;
    print_state(result);
    std::cout << "seleccione el segundo numero:\n";
    int row2 = select_row();
    int col2 = select_col();
    int number2 = select(array, row2, col2);

    if (number1 == number2){
      std::cout << "pareja correcta" << '\n';
      result[row2-1][col2-1] = 48 + number1;
      dct.at(number1) = true;
    } else {
      std::cout << "pareja incorrecta" << '\n';
      result[row1-1][col1-1] = '_';
    }

    if (comprobar(dct)) {
      std::cout << "terminaste el juego" << '\n';
      break;
    }
  }
  print_state(result);
}

int main() {
  game2();
  return 0;
}
