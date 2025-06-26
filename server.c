#include <stdio.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd; 
    // sockets do servidor e do cliente
    
    struct sockaddr_in server_addr, client_addr;
    // enderecos do servidor e do cliente
    
    socklen_t client_size = sizeof(client_addr);
    // tamanho da struct client_addr (para accept)
    
    char buffer[BUFFER_SIZE];
    // buffer para armazenar dados recebidos
    
    // cria o socket
    // configura o endereço do servidor
    // associa socket a porta
    // comeca a escutar
    // aceita uma conexão
    // abre arquivo para escrita
    // recebe dados e salva
    // fecha conexões
    
    return 0;
}
