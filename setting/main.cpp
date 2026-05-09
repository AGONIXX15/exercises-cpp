#include <iostream>
#include <fstream>
#include <filesystem>
#include <format>

void write_file(std::filesystem::path path) {
  std::filesystem::create_directories(path);
  std::ofstream file_writer(std::format("{}/main.cpp",path.string()),std::ios::app);
  file_writer << "#include <bits/stdc++.h>\n" << '\n';
  file_writer << "using namespace std;\n" << '\n';
  file_writer << "int main() {" << '\n';
  file_writer << "\tcin.tie(nullptr);" << '\n';
  file_writer << "\tios::sync_with_stdio(0);" << '\n';
  file_writer << "\nreturn 0;\n}";
}

// setcomp is a tool made by me for setting my dirs to competitive programming
int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cout << "use setcomp <name_of_dirs...>" << '\n';
  }
  
  for(int i = 1; i < argc; ++i) {
    write_file(std::filesystem::path(argv[i]));
  }
  return 0;
}
