#include "editor.hpp"
#include <fstream>
#include <ncurses.h>

Editor::Editor() : cursorX(0), cursorY(0), mode(Mode::NORMAL) {}

void Editor::openFile(const std::string &fname) {
  filename = fname;
  std::ifstream file(fname);
  std::string line;
  while (std::getline(file, line)) {
    buffer.push_back(line);
  }
  if (buffer.empty())
    buffer.push_back("");
}

void Editor::draw() {
  // Dibuja el buffer en pantalla (mínimo ejemplo)
  for (size_t i = 0; i < buffer.size(); ++i) {
    mvprintw(i, 0, "%s", buffer[i].c_str());
  }
  move(cursorY, cursorX);
  refresh();
}

void Editor::processKey(int ch) {
  if (ch >= 32 && ch <= 126) { // caracteres imprimibles
    if (cursorY >= buffer.size())
      buffer.push_back("");
    buffer[cursorY].insert(cursorX, 1, ch);
    cursorX++;
  } else if (ch == KEY_BACKSPACE || ch == 127) {
    if (cursorX > 0) {
      buffer[cursorY].erase(cursorX - 1, 1);
      cursorX--;
    }
  } else if (ch == '\n') {
    // Salto de línea simple
    std::string newLine = buffer[cursorY].substr(cursorX);
    buffer[cursorY] = buffer[cursorY].substr(0, cursorX);
    buffer.insert(buffer.begin() + cursorY + 1, newLine);
    cursorY++;
    cursorX = 0;
  }
  switch (ch) {
  case 'h':
    if (cursorX > 0)
      cursorX--;
    break;
  case 'l':
    cursorX++;
    break;
  case 'k':
    if (cursorY > 0)
      cursorY--;
    break;
  case 'j':
    cursorY++;
    break;
  case 'q':
    endwin();
    exit(0);
    break; // salir con 'q'
    //
  }
}

void Editor::run() {
  initscr();
  noecho();
  raw();
  keypad(stdscr, TRUE);

  while (true) {
    clear();
    draw();
    int ch = getch();
    processKey(ch);
  }

  endwin();
}
