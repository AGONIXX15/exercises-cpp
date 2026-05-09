#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>


void make_response(int client_fd) {
  std::string line;
  std::cout << "escribe tu mensaje: ";
  std::getline(std::cin,line);
  
  write(client_fd, line.c_str(), line.size());
  close(client_fd);
}

int main() {

  int fd_sock = socket(AF_INET,SOCK_STREAM,0);
  sockaddr_in addr;
  addr.sin_port = htons(8080);
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  socklen_t addrlen = sizeof(addr);

  if(bind(fd_sock, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
    std::cerr << "binding error: " << std::strerror(errno) << std::endl;
    return 1;
  }

  listen(fd_sock, 5);

  std::cout << "listening in localhost:8080" << std::endl;
  while(true) {
    int client = accept(fd_sock, (struct sockaddr *)&addr, &addrlen);

    if(client < 0) {
      std::cerr << "accept failed: " << std::strerror(errno) << std::endl;
    }

    make_response(client);
  }
  return 0;
}

