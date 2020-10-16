#include "incr-array.h"


void incr_array(int a[], int size) {
  size--;
  while (size >= 0) {
    a[size]++;
    size--;
  }
}
