#include <inttypes.h>
void main() {
	int64_t i;
	i=0;
	char a;
	a = toto('a','b');
	putchar(a);
}

char toto(char c,char d)
{
	putchar('a');
	return 'y';
}
