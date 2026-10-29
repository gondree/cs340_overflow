#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int x = 0x11223344;
    char buffer[8] = "hello";

    if (argc > 1) {
        strcpy(buffer, argv[1]);
    }

    printf("buffer = %s\n", buffer);
    printf("x      = 0x%x\n", x);

    return 0;
}
