
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {

  //Configurando ncurses
  raw();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);


  int socket_fd;
  struct sockaddr_in target;

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("Socket criado\n");

  target.sin_family = AF_INET;
  target.sin_port = htons(3001);
  inet_aton("127.0.0.1", &(target.sin_addr));
  printf("Tentando conectar\n");
  if (connect(socket_fd, (struct sockaddr*)&target, sizeof(target)) != 0) {
    printf("Problemas na conexao\n");
    return 0;
  }
  printf("Conectei ao servidor\n");

  char enviar = 0;


  /* Agora, meu socket funciona como um descritor de arquivo usual */
  while(enviar != 'q')
  {
    enviar = getchar();
    if(enviar != ERR) send(socket_fd, &enviar, 1, 0);
  }

  close(socket_fd);
  return 0;
}

