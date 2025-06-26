#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo_para_enviar>\n", argv[0]);
        return 1;
    }
    
    const char *file = argv[1];
    
    int sockfd;
    // socket do cliente para conexão com o servidor
    
    struct sockaddr_in server_addr;
    // endereco do servidor -> IP e porta
    
    char buffer[BUFFER_SIZE];
    // buffer para enviar ou receber dados

    // cria socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // configura servidor
    server_addr.sin_family = AF_INET;                     // ipv4
    server_addr.sin_port = htons(PORT);                   // porta do servidor
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr); // ponverte ip string para formato binario
        
    // conecta ao servidor
    connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Conectado ao servidor!\n");
    
    // abre arquivo para leitura
    FILE *fp = fopen(file, "rb");
    if (!fp) {
        perror("Erro ao abrir arquivo");
        close(sockfd);
        return 1;
    }
    
    // envia dados
    int bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        send(sockfd, buffer, bytes, 0);
    }
    printf("Arquivo enviado com sucesso!\n");
    fclose(fp);
    
    // fecha conexão
    close(sockfd);
    
    return 0;
}
