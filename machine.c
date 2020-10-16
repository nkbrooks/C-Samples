/*Natalie Brooks - 116009829 - Project 3*/
#include <stdio.h>
#include "machine.h"

void print_instruction(Hardware_word instruction);

unsigned int encode_instruction(unsigned short opcode, unsigned short reg1, unsigned short reg2,
  unsigned short reg3, unsigned int addr_or_constant, Hardware_word *const hw_word);

unsigned int diassemble(const Hardware_word memory[], unsigned int memory_size, unsigned int num_instrs);

unsigned int compare_instructions(Hardware_word instr1, Hardware_word instr2);

/* prints the components of the instuctions on a single output line*/
void print_instruction(Hardware_word instruction){
  
  /*opcodes*/
  const char* codes[]= {"halt","add", "sub", "mul", "div", "rem",
			"inv", "and", "or", "not", "cmp", "mv", "li", "load","store"};
  
  Hardware_word opcode, reg1, reg2,reg3,address;
   
  opcode = (instruction >> 28);
  if (opcode < 15) {

    /*reads reg1*/
    reg1 = (((instruction >> 20) & 0xf8));
    reg1 >>= 3;
	  
    /*reads reg2*/
    reg2 = (((instruction >> 16) & 0x7C));
    reg2 >>= 2;
	  
    /*reads reg3*/
    reg3 = (((instruction >> 12) & 0x3e));
    reg3 >>= 1;

    /*reads address*/
    address = (instruction & 0x1FF);
    
    /*formatting spaces based on length of each component*/
    if (opcode == 8 || opcode == 11 || opcode == 12) {
      printf("%s   ", codes[opcode]);
      
    } else if (opcode == 0 || opcode == 14){ 
      printf("%s", codes[opcode]);
      
    } else if (opcode == 13){
      printf("%s ", codes[opcode]);

    } else {
      printf("%s  ", codes[opcode]);
      
    }
	  
    if (reg1 != 0) {
      if (reg1 > 10) {
	printf(" R%d", reg1);
	
      } else {
	printf(" R%d ", reg1);
	
      }
    }
    
    if (reg2 != 0) {
      if (reg2 > 10) {
	printf(" R%d", reg2);
	
      } else {
	printf(" R%d ", reg2);
	
      }
    }
    
    if (reg3 != 0) {
      if (reg3 > 10) {
	printf(" R%d", reg3);
	
      } else {
	printf(" R%d ", reg3);
	
      }
    }
    
    if (address != 0 && opcode == 12 && opcode != 0) {
      printf(" %d", address);
      
    }
    
    if (address != 0 && opcode != 12 && opcode != 0) {
      printf(" 0%d", address);

    }
  }
             
}

/*This function takes in components of instruction and encodes it into 32 - bit Mathlon instruction*/
unsigned int encode_instruction(unsigned short opcode, unsigned short reg1, unsigned short reg2, unsigned short reg3,
				unsigned int addr_or_constant, Hardware_word *const hw_word){

  Hardware_word binary_num = 0x00000000;
  
  /*checks for valid conditions*/
  if (hw_word != NULL) {
    if ((reg1 >= 0 && reg1 <= 19)&&(reg2 >= 0 && reg2 <= 19)&& (reg3 >= 0 && reg3 <= 19)&&(opcode >= 0 && opcode <= 15)) {
  
      /*encodes opcode*/
      binary_num = ((binary_num | opcode) << 5);
		  
      /*encodes reg1*/
      binary_num = ((binary_num | reg1) << 5);
      
      /*encodes reg2 */
      binary_num = ((binary_num | reg2) << 5);
		   
      /*encodes reg3*/
      binary_num = ((binary_num | reg3) << 13);
      
      /*encodes address*/
      binary_num = (binary_num | addr_or_constant);
      
      /*reassigns pointer value*/
      *hw_word = binary_num;
      
      return 1;
      
    } else {
      *hw_word = 0;

    }
  }

  return 0;

}

/*This functions reads throw the hardware's memory and utlizies the print_function to prints all instructions
  under the designated conditions*/

unsigned int disassemble(const Hardware_word memory[], unsigned int memory_size, unsigned int num_instrs){
  
  Hardware_word opcode;
  int i = 0;
  static int address =  0x000;
  int count = num_instrs;
  
  if (memory != NULL && memory_size != 0 && memory_size <= NUM_WORDS
     && num_instrs != 0 && (num_instrs <= memory_size)) {

    for (i = 0; i < memory_size; i++) {
      opcode = (memory[i] >> 28);

      /*checks if opcode and address valid before printing and formatting address in hex*/
      if (opcode < 15) {
	if (address < 16 && address >= 0) {
	  printf("00%x: ", address);
      
	} else if (address >= 16 && address < 256) {
	  printf("0%x: ", address);	  

	} else {
	  printf("%x: ", address);
	  
	}
	/*increments address*/
        address += 4;
	--count;
	/*prints instruction memory if count is 0 or greater*/
	if (count >= 0) {
	  print_instruction(memory[i]);
	  
	  /*prints undeciphered instructions if num_instrs is less than 0*/
	} else {
	  if (memory[i] < 10000000) {
	    printf("00%x", memory[i]);
	    
	  } else if (memory[i] >= 10000000 && memory[i] < 100000000 ) {
	    printf("0%x", memory[i]);               

	  } else {
	    printf("%x", memory[i]);
	    
	  }
	}
	printf("\n");
	
      } else {
	return 0;
	
      }
    }
    return 1;
    
  }
  return 0;

}

/*This function takes in two instructions and compares if they are the same with bitmapping*/
unsigned int compare_instructions(Hardware_word instr1, Hardware_word instr2){
  Hardware_word ans;
  if (instr1) {
    if (instr2) {
      ans = (instr1 & instr2);
      /*uses bit mapping to compare functions*/
      if ((ans == instr1) && (ans == instr2)) {
	return 1;
	
      } 
    }
  }
  return 0;
  
}

