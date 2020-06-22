#include <stdio.h>    // for lprint instruction
#include <fcntl.h>    // ok for mmap param
#include <sys/mman.h> // ok for mmap
#include <unistd.h>

#define SCM_INTERFACE_BASE 0x48002000
#define SCM_PADCONFS_BASE 0x48002030
#define CONTROL_PADCONF_SYS_NIRQ (*(volatile unsigned long *)0x480021E0)
#define CONTROL_PADCONF_SYS_NIRQ_OFFSET 0x1B0

#define GPIO6_BASE 0x49058000
#define GPIO6_SYSCONFIG_OFFSET 0x10
#define GPIO6_CLEARDATAOUT_OFFSET 0x90
#define GPIO6_SETDATAOUT_OFFSET 0x94

#define GPIO6_OE_OFFSET 0x34
#define GPIO6_CTRL_OFFSET 0x30

#define MAP_SIZE (volatile unsigned long)4 * 1024
#define MAP_MASK (volatile unsigned long)(MAP_SIZE - 1)

#define u32 volatile unsigned long
u32 *A;
u32 *B;

int main(void)
{
    unsigned long i;
    int fd;

    fd = open("/dev/mem", O_RDWR | O_SYNC);

    A = (u32 *)mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, SCM_INTERFACE_BASE & ~MAP_MASK);

    *(u32 *)((u32)A + 0x30 + CONTROL_PADCONF_SYS_NIRQ_OFFSET) &= (0xfff8ffff);
    *(u32 *)((u32)A + 0x30 + CONTROL_PADCONF_SYS_NIRQ_OFFSET) |= (0x00040000); //set mode 4 on the pad 186 configuration register; enables digital pin use

    close(fd);
    /*****************************************************/

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    B = (volatile unsigned long *)mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO6_BASE & ~MAP_MASK); // COM1 0x4806A000

    //gpio_186 handling
    *(u32 *)((u32)B + GPIO6_SYSCONFIG_OFFSET) &= 0xffffffe0;
    *(u32 *)((u32)B + GPIO6_SYSCONFIG_OFFSET) |= 0x00000014; // bit2=1 enable/wake up, free running clock

    *(u32 *)((u32)B + GPIO6_CTRL_OFFSET) &= 0xfffffff8; // bit0=0, bit1=0, bit2=0 module enabled , clock not gated, clock= interface clock not divided

    *(u32 *)((u32)B + GPIO6_OE_OFFSET) &= 0xfbffffff; //bit26=0, gpio_186 output

    // generate a pulse stream on gpio_186 pin output

    for (i = 0; i < 100000; i++)
    {
        *(u32 *)((u32)B + (GPIO6_SETDATAOUT_OFFSET)) |= 0x04000000;
        // printf("Saida = 1\n");
        // usleep(500000);
        *(u32 *)((u32)B + (GPIO6_CLEARDATAOUT_OFFSET)) |= 0x04000000;
        // printf("Saida = 0\n");
        // usleep(500000);
    }
    close(fd);
    return (0);
}