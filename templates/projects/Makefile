CC = gcc
CFLAGS = -Wall -Wextra -m32 -masm=intel -nostdlib -fno-builtin

main: main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	-rm main
