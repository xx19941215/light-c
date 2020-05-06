#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>

int main()
{
    char buffer[4096] = "/Users/xiao/Code/githubRepo/xiao/light-c/c04/c04_7/client.php", actualpath[1024];

    if (realpath(buffer, actualpath) == NULL) {
        printf("ERROR(bad path): %s\n", buffer);
        printf("Error no.%d: %s\n", errno, strerror(errno));
    }

    FILE* fp = NULL;
    fp = fopen(actualpath, "r");

    char buff[1024];
    
    while (fgets(buff, 1024, fp) != NULL) {
        printf("%s", buff);
    }

    fclose(fp);
    return 0;
}