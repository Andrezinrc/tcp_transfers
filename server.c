#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
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
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // configura o endereço do servidor
    server_addr.sin_family = AF_INET;         // ipv4
    server_addr.sin_port = htons(PORT);       // porta do servidor
    server_addr.sin_addr.s_addr = INADDR_ANY; // aceita conexões em qualquer interface de rede

    // associa socket a porta
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // comeca a escutar
    listen(server_fd, 5);
    printf("Servidor ouvindo na porta %d...\n", PORT);

    // aceita uma conexão
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_size);
    printf("Cliente conectado!\n");

    // recebe o nome do arquivo enviado pelo cliente e o cria para escrita
    int filename_len;
    recv(client_fd, &filename_len, sizeof(int), 0);

    char filename[256] = {0};
    recv(client_fd, filename, filename_len, 0);

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Erro ao abrir arquivo");
        close(client_fd);
        close(server_fd);
        return 1;
    }

    // recebe dados e salva
    int bytes;
    while ((bytes = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes, fp);
    }

    // fecha conexões
    close(client_fd);
    close(server_fd);
    return 0;

    return 0;
}
