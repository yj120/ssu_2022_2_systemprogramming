#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned char *pointer;

bool is64bit()
{

	size_t s = sizeof(long long);
	if (s == 8)
	{
		return true;
	}
	else
	{
		return false;
	};
}

bool isBigEndian()
{
	int i = 0x0000001; // LSB : 1
	if (((char *)&i)[0])
	{				  // 1-> TRUE
		return false; // -> little endian 이다.
		// return true; // test용
	}
	else
	{
		return true;
	};
}

void le_show_bytes(pointer start, int len) // little-endian
{

	// size_t i;
	// int i = len-1;

	for (int i = len - 1; i >= 0; i--)
	{
		printf("%.2X", start[i]);
	};

	printf("\n");
	return;
}

void be_show_bytes(pointer start, int len) // big-endian
{
	// size_t i;
	for (int i = 0; i < len; i++)
	{
		printf("%.2X", start[i]);
	};
	printf("\n");
	return;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: ./a.out number\n");
		exit(0);
	}

	unsigned int a = atoi(argv[1]);

	printf("ARCH=%d\n", is64bit() ? 64 : 32);
	printf("ORDERING=%s\n", isBigEndian() ? "BIG_ENDIAN" : "LITTLE_ENDIAN");

	printf("MYANS: DEC=%d HEX=", a);
	isBigEndian() ? be_show_bytes((pointer)&a, sizeof(int)) : le_show_bytes((pointer)&a, sizeof(int));
	// be_show_bytes((pointer)&a, sizeof(unsigned int)): le_show_bytes((pointer)(&a), sizeof(unsigned int));

	printf("CHECK: DEC=%d HEX=%.8X\n", a, a);
	return 0;
}
