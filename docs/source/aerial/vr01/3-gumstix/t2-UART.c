#include <termios.h>
#include <stdio.h>
#include <string.h>

int main()
{

    int UART1 = configUART1();
    char dis[2], out[100], string[100];

    printf("Que dispositivo eu sou?");
    scanf("%c", &dis[0]);
    dis[1] = 0;
    string[0] = 0;
    strcat(string, "Ola! Essa e uma mensagem do dispositivo ");
    strcat(string, dis);

    // testa UART
    write(UART1, string, strlen(string));
    sleep(1);
    read(UART1, out, 100);
    printf("Mensagem lida pelo dispositivo %s: %s\n", dis, out);
    close(UART1);
    return 0;
}