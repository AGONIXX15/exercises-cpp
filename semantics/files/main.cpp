#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read_file(std::string file_name) {
  std::ifstream fr(file_name);
  if(!fr.is_open()){
    throw std::runtime_error("cannot open the file");
  }
  std::string line;
  std::vector<std::string> tokens;
  while(std::getline(fr, line)){
    tokens.push_back(std::move(line));
  }
  return tokens;
}

int main(int argc, char* argv[]){
  if (argc == 2){
    auto v = read_file(argv[1]);
    for(auto line: v){
      std::cout << line << std::endl;
    }
  }
}
