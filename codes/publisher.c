#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "News.h"

news nuevaNoticia;

int main(int argc, char const *argv[])
{
    int fd, bytes;
    char const *filename = argv[2];
    char *token;
    char *mensaje;
    mode_t fifo_mode = S_IRUSR | S_IWUSR;
    FILE *fp = fopen(filename, "r");
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    char delimitador[] = ":";
    if (argc != 3)
    {
        perror("\tNumero de argumentos invalidos\n");
        printf("\t[] argumento opcional \n");
        exit(0);
    }
    if (fp == NULL)
    {
        perror("Error: could not open file\n");
        printf("%s", filename);
        exit(0);
    }
    else
    {
        while (fgets(buffer, MAX_LENGTH, fp))
        {
            
        }
        unlink(argv[1]);
        if (mkfifo(argv[1], fifo_mode) == -1)
        {
            perror("\t[!]Request mkfifo");
            exit(1);
        }
        fd = open(argv[1], O_WRONLY);
        if (fd == -1)
        {
            perror("no se puso iniciar el pipe de envio");
            exit(0);
        }
        bytes = read(fd, &nuevaNoticia, sizeof(nuevaNoticia));
        fclose(fp);
    }
    return 0;
}