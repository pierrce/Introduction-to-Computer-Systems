/* Assignment1 intcat
 * by Alec Pierce, Lecture 2 and Dan Hayes, Lecture 1
 * September 25, 2014
 *
 * The program takes an input .int file and
 * prints the content of that file one line
 * at a time.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>

/*main takes an input .int file and
 * prints the content of that file one line
 * at a time.
 *Parameters:
 * fd: Variable for file name
 * buffer: Variable for buffer of the read inputs
 */

int main(int argc, char *argv[])
{

  int fd;  
  int buffer;

  /* Error checking for incorrect number of input parameters*/
  if (argc != 2)
  {
    fprintf(stderr, "usage: intcat <input_file>\n");
    exit(1);
  }

  /* Opens input file and Error checks for unknown/unreadable file*/
  if ((fd = open(argv[1], O_RDONLY)) < 0)
  {
    printf("Could not open file: %s\n", argv[1]);
    exit(1);
  }

  /* main loop, reads line from file and prints them using printf*/
  while(read(fd, &buffer, sizeof(int)) != 0)
  {
    printf("%d\n", buffer);
  }

  /* Colses file and Error checks for faileure to close file*/
  if (close(fd) == -1) 
  {
        fprintf(stderr, "error closing file -- quitting");
	exit(1);
  }

  return 0;

}
