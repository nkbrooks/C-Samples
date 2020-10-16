#include <stdio.h>
#include <assert.h>
#include "machine.h"

#define UNUSED 0


int main() {
  Hardware_word instr;
  /*remove this*/
  Hardware_word temp;
  int binary_num[32];
  int i = 0;

  encode_instruction(NOT, R7, R6, UNUSED, UNUSED, &instr);
   printf("binary: %d\n", instr);
  temp = instr;
    while (temp > 0) { 
      binary_num[i] = temp % 2;
       printf("%x", binary_num[i]);
       temp = temp / 2; 
        i++; 
	}
    return 0;
}
