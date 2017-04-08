#include <inttypes.h>
void main() {
	char a;
	a = toto('o','k');
	putchar(a);
}

char toto(char c,char d)
{
	putchar(c);
	putchar(d);
	return 33;
}
