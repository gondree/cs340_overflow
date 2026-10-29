#include <stdio.h>
#include <string.h>

void copy_message(char *message)
{
    char buffer[16];

    strcpy(buffer, message);
    printf("Copied: %s\n", buffer);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s MESSAGE\n", argv[0]);
        return 1;
    }

    copy_message(argv[1]);
    printf("Back in main!\n");

    return 0;
}