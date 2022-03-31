#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "News.h"


news nuevaNoticia;

int main(int argc, char const *argv[])
{

    if (argc != 2)
    {
        perror("\tNumero de argumentos invalidos\n");
        printf("\t[] argumento opcional \n");
        exit(0);
    }
    mode_t fifo_mode = S_IRUSR | S_IWUSR;
    int fd, bytes;
    unlink(argv[1]);
    if (mkfifo(argv[1], fifo_mode) == -1)
    {
        perror("\t[!]Request mkfifo");
        exit(1);
    }
    fd = open(argv[1], O_WRONLY);
    bytes = read (fd, &nuevaNoticia, sizeof(nuevaNoticia));




    return 0;
}
