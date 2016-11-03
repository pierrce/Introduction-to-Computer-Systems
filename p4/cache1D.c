/* Assignment4 cache1D
 * by Alec Pierce, section 2
 *
 * This program creates an array of size 100000, and then 
 * sets the value of each location to its location.
 */

#include <stdio.h>

int numbers[100000];

int main() {

  int x;

  for(x = 0; x < 100000; x++){

    numbers[x]=x;

  }

  return 0;
}
