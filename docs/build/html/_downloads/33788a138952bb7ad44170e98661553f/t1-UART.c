// função para configuração da comunicação serial 

#include <termios.h>

int configUART1()
{
    // Define variaveis locais
    struct terios cUART1;
    int UART1 = open("/dev/ttyO0",O_RDWR);

    if(tcgetattr(UART1,&cUART1))
        printf("Erro tcgetattr");   // responde em caso de erro de execução
    cfmakeraw(&cUART1); // configura o funcionamento sem bit de paridade e com 8 bits de dados
    cfsetspeed(&cUART1,B115200);    // configura a velocidade em baud
    cUART1.c_cflag &= ~CSTOPB;

    cUART1.c_cc[VMIN] = 1;  // número mínimo de bits que se espera ser lido
    cUART1.c_cc[VTIME] = 1; // tempo máximo de espera pelo próximo bit em décimos de segundo
    if (tcsetattr(UART1, TCSANOW, &cUART1)) // aplica as alterações sejam feitas na UART
        printf("Erro tcsetattr"); // responde em caso de erro de execução
        
    return UART1;
}
