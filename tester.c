#include <stdio.h>
#include "fill-array.h"
#include "incr-array.h"
#include "sum-array.h"


int main(void) {
  int arr[10];

  complete_array(arr, 0, 9, 2);
  printf("%d\n", sum_array(arr, 10));

  increase_size_array(arr, 10);
  printf("%d\n", sum_array(arr, 10));

  return 0;
}
