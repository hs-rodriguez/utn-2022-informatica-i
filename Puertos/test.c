#include <stdio.h>
#include <sys/io.h>

#define PORT 0x400

int main(void)
{
    unsigned char lecture;

    ioperm(PORT, 1, 1);

    lecture = inb(PORT);

    ioperm(PORT, 1, 0);

    printf("Se leyo en el puerto 0x400: %ud", lecture);

    return 0;
}
