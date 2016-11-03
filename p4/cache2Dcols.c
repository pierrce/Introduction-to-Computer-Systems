/* Assignment4 cache2Dcols
 * by Alec Pierce, section 2
 *
 * This program creates a 2D array and then sets the value 
 * of each location to the rows+cols of the location.
 */

#include <stdio.h>

int numbers[3000][500];

int main() {

  int rows = 0;
  int cols = 0;

  for(cols = 0; cols < 500; cols++){

    for(rows = 0; rows<3000; rows++) {
      numbers[rows][cols] = rows + cols;
    }

  }

  return 0;
}

