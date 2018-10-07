/*
 *  Rodrigo Oliveira Caus - 186807
 *  Victor Ferrão Santolim - 187888
 */

#ifndef TECLADOSERVER_HPP
#define TECLADOSERVER_HPP

#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void threadFunctionServer(char *keybuffer, int *control,  int *socket_fd,  int *connection_fd, struct sockaddr_in *client, socklen_t client_size);

class TecladoServer {
  private:

    int socket_fd, connection_fd;
    struct sockaddr_in myself, client;

    char ultimaCaptura;
    int rodando;

    std::thread kbThread;

  public:
    TecladoServer();
    ~TecladoServer();
    void stop();
    char getCharServer();
    void initServer();
};

#endif
