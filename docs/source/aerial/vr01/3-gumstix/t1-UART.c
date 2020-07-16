// função para configuração da comunicação serial 

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

void main()
{
    struct termios cUART1;
    int UART1 = open("/dev/ttyO0", O_RDWR);

    if(tcgetattr(UART1,&cUART1))
        printf("Erro tcgetattr");
    cfmakeraw(&cUART1);
    cfsetspeed(&cUART1,B115200); 
    cUART1.c_cflag &= ~CSTOPB;

    cUART1.c_cc[VMIN] = 1;
    cUART1.c_cc[VTIME] = 1;
    if (tcsetattr(UART1, TCSANOW, &cUART1))
        printf("Erro tcsetattr");

}