#include <stdio.h>
#include "complete-array.h"
#include "compare-arrays.h"

int main(void) {
  int arr1[10];
  int arr2[10]= {216, 216, 216, 216, 216, 216, 216, 216, 216, 216};

  complete_array(arr1, 0, 3, 250);
  printf("%d\n", compare_arrays(arr1, arr2, 10));

  complete_array(arr1, 0, 9, 216);
  printf("%d\n", compare_arrays(arr1, arr2, 10));

  return 0;
}
