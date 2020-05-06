#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>


#define SERVERPORT 8989
#define BUFFSIZE 4096
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 1

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;


void handle_connection(int client_socket);
int check(int exp, const char *msg);

int main() {
    int server_socket, client_socket, addr_size;
    SA_IN server_addr, client_addr;
    check(server_socket = socket(AF_INET, SOCK_STREAM, 0), "Failed to create socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVERPORT);

    check(bind(server_socket, (SA*)&server_addr, sizeof(server_addr)), "Bind Failed");
    check(listen(server_socket, SERVER_BACKLOG), "Listen Failed");

    while(true) {
        printf("Waiting for connection....\n");
        //wait for and eventually accept an incoming connection
        addr_size = sizeof(SA_IN);
        check(client_socket = accept(server_socket, (SA*)&client_addr, (socklen_t*)&addr_size), "accept failed");
        printf("Connected!\n");
        handle_connection(client_socket);
    }

    return 0;
}

void handle_connection(int client_socket)
{
    char buffer[BUFSIZ];
    size_t bytes_read;
    int msgsize = 0;
    char actualpath[PATH_MAX + 1];

    //read the client's message the name of the file to read
    while((bytes_read = read(client_socket, buffer + msgsize, sizeof(buffer) - msgsize - 1)) > 0) {
        msgsize += bytes_read;
        if (msgsize > BUFSIZ - 1 || buffer[msgsize-1] == '\n') {
            break;
        }
    }

    check(bytes_read, "recv error");
    buffer[msgsize-1] = 0;//null terminate the message and remove the \n

    printf("REQUEST:%s\n", buffer);
    fflush(stdout);

    //validity check
    if (realpath(buffer, actualpath) == NULL) {
        printf("ERROR(bad path): %s\n", buffer);
        printf("Error no.%d: %s\n", errno, strerror(errno));
        close(client_socket);
        return;
    }

    // read the file and send its contents to client
    FILE *fp = fopen(actualpath, "r");
    if (fp == NULL) {
        printf("ERROR(open):%s\n", buffer);
        close(client_socket);
        return;
    }


    //read the file contents and send them to client
    //note this is a fine example program, but rather insecure.
    //a real program would probably limit the client to certain file.
    while((bytes_read = fread(buffer, 1, BUFFSIZE, fp)) > 0) {
        printf("sending %zu bytes\n", bytes_read);
        write(client_socket, buffer, bytes_read);
    }

    close(client_socket);
    fclose(fp);
    printf("closing connection\n");
}

int check(int exp, const char *msg)
{
    if (exp == SOCKETERROR) {
        perror(msg);
        exit(1);
    }

    return exp;
}
