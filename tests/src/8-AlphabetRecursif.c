void main() {
   int64_t i;
   char c;
   i = 0;
   c='a';

	alphabet(c,i);
}

void alphabet(char c, int64_t i)
{
	if(i<26)
	{
		putchar(c);
		c++;
		i++;
		alphabet(c,i);
	}
}
