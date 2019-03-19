#include <stdio.h>

int main (void)
{
	/* Insert shellcode here: */

	return ((int(*)(void))shellcode)();
}
