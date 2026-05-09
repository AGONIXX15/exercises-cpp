#include <iostream>
#include <editor.hpp>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    Editor ed;
    ed.openFile(argv[1]);
    ed.run();

    return 0;
}
