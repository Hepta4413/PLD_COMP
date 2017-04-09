void main() {
   int64_t i;
   int64_t j;
   char c;
   i = 0;
   j = 0;

   while(i < 4)
   {
	   c='a';
	   for(j=0;j<26;j++)
	   {
		   putchar(c);
		   c++;
	   }
	   i++;
	   putchar(10);
   }	
}
