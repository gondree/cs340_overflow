#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void buffer_overflow(const char * str)
{
    char buffer[12];
    printf("buffer is at %x\n", buffer);
    strcpy(buffer, str);    /* this is unsafe */
    return;
}

int main(int argc, char ** argv)
{
    char aString[512];
    FILE *fs;

    if (argc != 2 ||  argv[1] == NULL) {
        fprintf(stderr, "Error: First argument is path to egg\n"); exit(1);
    } else if ((fs = fopen(argv[1], "r")) == NULL){
        perror(argv[1]); exit(2);
    }

    printf("Reading from %s into a big buffer...\n", argv[1]);
    fread(aString, sizeof(char), 512, fs);

    printf("Doing an uncontrolled copy into a small buffer\n");
    buffer_overflow(aString);
    printf("buffer_overflow() returned\n");

    fclose(fs);

    return 1;
}

