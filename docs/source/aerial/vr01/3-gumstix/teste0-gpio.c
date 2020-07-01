#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main()
{
    int i;
    int arq = open("/sys/class/gpio/export", O_WRONLY);
    write(arq, "10", 2);
    close(arq);

    arq = open("/sys/class/gpio/gpio10/direction", O_WRONLY);
    write(arq, "out", 3);
    close(arq);

    arq = open("/sys/class/gpio/gpio10/value", O_RDWR);
    
    system("cls");

    do
    {

        printf("0 ->bit 0 \n1 ->bit 1\n2 ->SAIR\n");
        scanf("%i", &i);

        switch (i)
        {
        case 0:
        {
            write(arq, "0", 1);
            printf("Saida = 0\n\n");
        }

        case 1:
        {
            write(arq, "1", 1);
            printf("Saida = 1\n\n");
        }
        
        case 2:
            break;
        }
        while (i != 2);

        close(arq);
        return 0;
    }