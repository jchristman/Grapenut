CC = gcc
CFLAGS = -Wall -Wextra

grapenut: grapenut.c
	$(CC) $(CLFAGS) -o $@ -masm=intel -m32 $<

.PHONY:
clean:
	-rm grapenut
