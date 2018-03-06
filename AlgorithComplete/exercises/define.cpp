#include <stdio.h>
#define TEXT "hello,world,"
#define msg(x) puts(TEXT ## x)

int main()
{
	msg(" it's cobing");
	return 0;
}
