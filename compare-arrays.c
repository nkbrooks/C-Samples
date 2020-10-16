#include "compare-arrays.h"

int compare_arrays(int a[], int b[], int size) {
  int same= 1, i= 0;

  while (i < size && same)
    if (a[i] != b[i]) {
      same= 0;
    } else {
      i++;
    }
  return same;
}

