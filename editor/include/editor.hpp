#pragma once
#include <vector>
#include <string>

enum class Mode { NORMAL, INSERT };

class Editor {
public:
    Editor();
    void openFile(const std::string& filename);
    void run();
private:
    std::vector<std::string> buffer;
    int cursorX, cursorY;
    Mode mode;
    std::string filename;

    void draw();
    void processKey(int ch);
    void enterInsertMode();
    void enterNormalMode();
    void saveFile();
};

