#include <stdint.h>

void main() {
   int32_t a;
   a = 1;
   a = function(a);
}

int32_t function(int32_t a) {
	a++;
   return a+1;
}
   


