
testShellCode.x: testShellCode.c
	gcc -m32 -g -z execstack -fno-stack-protector testShellCode.c -o testShellCode.x

overflow0: overflow0.c
	gcc -m32 -g -z execstack -fno-stack-protector overflow0.c -o overflow0

