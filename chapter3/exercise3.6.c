#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int     fd;
    char    buf[] = "abcdefgh";

    if(argc != 2) {
        err_quit("usage: a.out filename");
    }

    if((fd = open(argv[1], O_RDWR | O_APPEND)) < 0) {
        err_sys("open error");
    }

    if(lseek(fd, 5, SEEK_SET) < 0) {
        err_sys("lseek error");
    }

    if(write(fd, buf, 5) != 5) {
        err_sys("write error");
    }

    exit(0);
}
