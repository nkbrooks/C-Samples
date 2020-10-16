#include <stdio.h>
#include "compare-arrays.h"


int main(void) {
  int arr1[]= {1, 1, 4, 1, 5, 9, 2, 6, 4, 7, 5, 9};
  int arr2[]= {1, 1, 4, 1, 5, 9, 2, 6, 4, 7, 5, 9};
  int arr3[]= {1, 1, 4, 5, 1, 9, 2, 6, 4, 7, 5, 9};

  printf("%d\n", compare_arrays(arr1, arr2, 12));
  printf("%d\n", compare_arrays(arr1, arr3, 12));

  return 0;
}
