#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char *line;
    line = get_next_line(fd);
    while(line)
    {
        printf("%s",line);
        free(line); 
        line = get_next_line(fd);
    }
    close(fd);
    return 0;
}