#include <stdio.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
    int sockfd;
    // socket do cliente para conexão com o servidor
    
    struct sockaddr_in server_addr;
    // endereco do servidor -> IP e porta
    
    char buffer[BUFFER_SIZE];
    // buffer para enviar ou receber dados

    // cria socket
    // configura servidor
    // conecta ao servidor
    // abre arquivo para leitura
    // envia dados
    // fecha conexão
    
    return 0;
}
