#include <termios.h>

int configUART1()
{
    struct terios cUART1;
    int UART1 = open("/dev/ttyO0",O_RDWR);
    if(tcgetattr(UART1,&cUART1))
        printf("Erro tcgetattr");
    cfmakeraw(&cUART1);
    cfsetspeed(&cUART1,B115200);
    cUART1.c_cflag &= ~CSTOPB;

    cUART1.c_cc[VMIN] = 1;
    cUART1.c_cc[VTIME] = 1;
    if (tcsetattr(UART1, TCSANOW, &cUART1))
        printf("Erro tcsetattr");
        
    return UART1;
}