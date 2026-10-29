CC = gcc
CFLAGS = -m32 -g -O0 -fno-stack-protector -fno-pie -no-pie -fno-omit-frame-pointer
LDFLAGS = -z execstack

all: memory stack overflow0

memory: memory.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

stack: stack.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

overflow0: overflow0.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -f memory stack overflow0
