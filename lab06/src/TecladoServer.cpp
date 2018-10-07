/*
 *  Rodrigo Oliveira Caus - 186807
 *  Victor Ferrão Santolim - 187888
 */

#include "model.hpp"
#include "TecladoServer.hpp"

//Função que roda em thread verificando input de teclado do computador remoto
void threadFunctionServer(char *keybuffer, int *control,  int *socket_fd,  int *connection_fd, struct sockaddr_in *client, socklen_t client_size)
{
  char c;
  //printf("Vou travar ate receber alguma coisa pela primeira vez\n");
  *connection_fd = accept(*socket_fd, (struct sockaddr*)client, &client_size);
  
  while ((*control) == 1) {
    //printf("Recebi uma mensagem:\n");
    recv(*connection_fd, &c, 1, 0);

    (*keybuffer) = c;
    std::this_thread::sleep_for (std::chrono::milliseconds(10));
  }
  return;
}

TecladoServer::TecladoServer() {
}

TecladoServer::~TecladoServer() {
}

void TecladoServer::initServer() {
  // Inicializa ncurses
  // raw();				         /* Line buffering disabled	*/
  // keypad(stdscr, TRUE);	 /* We get F1, F2 etc..		*/
  // noecho();			         /* Don't echo() while we do getch */
  // curs_set(0);           /* Do not display cursor */


  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  //printf("Socket criado\n");

  myself.sin_family = AF_INET;
  myself.sin_port = htons(3001);
  inet_aton("127.0.0.1", &(myself.sin_addr));

  //printf("Tentando abrir porta 3001\n");
  if (bind(socket_fd, (struct sockaddr*)&myself, sizeof(myself)) != 0) {
    fprintf(stderr , "Problemas ao abrir porta\n");
    return;
  }
  //printf("Abri porta 3001!\n");

  listen(socket_fd, 2);
  //printf("Estou ouvindo na porta 3001!\n");

  this->rodando = 1;
  (this->kbThread) = std::thread(threadFunctionServer, &(this->ultimaCaptura), &(this->rodando) , &(this->socket_fd) , &(this->connection_fd) , &(this->client) , (socklen_t)sizeof(this->client));
}

void TecladoServer::stop() {
  this->rodando = 0;
  (this->kbThread).join();
  close(socket_fd);
}

char TecladoServer::getCharServer() {
  char c = this->ultimaCaptura;
  this->ultimaCaptura = 0;
  return c;
}
