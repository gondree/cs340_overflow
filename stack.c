#include <stdio.h>
#include <string.h>

void copy_message(char *message)
{
    char buffer[16];

    strcpy(buffer, message);
    printf("Copied: %s\n", buffer);
}

int main(void)
{
    copy_message("hello");
    printf("Back in main!\n");
    return 0;
}
