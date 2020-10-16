#include "increase_array_size.h"


void increase_array_size(int a[], int size) {
  size--;
  while (size >= 0) {
    a[size]++;
    size--;
  }
}
