#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main()
{

    int arq = open("/sys/class/gpio/export", O_WRONLY);
    write(arq, "10", 2);
    close(arq);

    arq = open("/sys/class/gpio/gpio10/direction", O_WRONLY);
    write(arq, "out", 3);
    close(arq);

    arq = open("/sys/class/gpio/gpio10/value", O_RDWR);
    while (1)
    {
        write(arq, "1", 1);
        //usleep (500000);
        write(arq, "0", 1);
        //usleep (500000) ;
    }
    close(arq);

    return 0;
}