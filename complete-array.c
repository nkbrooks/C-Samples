#include "fill-array.h"

void complete_array(int arr[], int from, int to, int value) {
  int i;

  for (i= from; i <= to; i++)
    arr[i]= value;
}
