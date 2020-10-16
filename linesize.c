#include <stdio.h>
int main(){
 int line_count = 0; /* counts number of lines */
 int out_of_bounds = 0;
 char my_char; /* variable for each character */
 while ((scanf("%c",&my_char)) != EOF){ /* read character by character for newline */

 char newline[999]; /* array for holding chars from each line */
 int array_count = 0; /* array index */
 int  mod, eight_add = 0;
 int length = 0; /*counts number of characters*/
 int x; /* x for the printing line loop: output */
 newline[array_count] = my_char;
 array_count += 1;
 length += 1;
 
 while (my_char != '\n') {
 (scanf("%c",&my_char)); /* get another character */
  newline[array_count] = my_char; /* add char to your array */

 if (my_char == '\t') { /*if tab*/
  mod = length % 8;
   if (mod != 0) {
     eight_add = 8 - mod; /*what to add to length to make length divisble by 8 */
      length = length + eight_add;
   }
         array_count += 1;

 } else {
   array_count += 1;  /* increment the array index */
   length += 1; /*increment length*/
  }
 }

 newline[array_count] = '\n'; /* add newline to your array */
/* print line output for size<=80 */
 --length;
 --array_count;
 if (length < 80) {
   if (length < 10){
     /* if length less than 10*/
      printf("     %d> ", length);
         for (x = 0; x <= array_count; x++) {
           printf("%c", newline[x]);
    }
 } else {
    /* if length longer than 10 but shorter than 80*/
    printf("    %d> ", length);
       for (x = 0; x <= array_count; x++) {
          printf("%c", newline[x]);
     } 

   }

 } else if (length > 80 && length < 100) {
   /*if length is longer than 80 and less than 100*/
     printf("X   %d> ", length);
      for (x = 0; x <= array_count; x++) {
         printf("%c", newline[x]);
      }
            out_of_bounds += 1;

 } else {
   /*if length is atleast 100*/
  printf("X  %d> ", length);
  
  for (x = 0; x <= array_count; x++) {
    printf("%c", newline[x]);
      }
    out_of_bounds += 1;
    }
 line_count += 1; /* increment line number */

  }
 printf("%d %d\n", line_count, out_of_bounds);/*prints number of lines and outofbounds*/
  
 /* end of outside while loop */
  

  return 0;

 }
