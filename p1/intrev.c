/* Assignment1 intrev
 * by Alec Pierce, Lecture 2 and Dan Hayes, Lecture 1
 * September 25, 2014
 *
 * The program takes an input .int file and
 * creates an output .int file which is the
 * same as the input file, but with the values
 * reversed.
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
 * creates an output .int file which is the
 * same as the input file, but with the values
 * reversed.
 *Parameters 
 * infile: Pointer variable for input file name
 * outfile: Pointer variable for output file name
 * buffer: Variable for buffer of the read inputs
 * fi: variable for opened input file 
 * fo: variable for opened output file
 * size: size of the arrary that p points to
 * p: Pointer for address of an array used with the malloc function
 */

int main(int argc, char *argv[])
{

  /* Error checking for incorrect number of input parameters*/
  if (argc != 3) 
  {
    fprintf(stderr, "usage: intrev <input_file> <output_file>\n");
    exit(1);
  }

  char *infile = argv[1];  
  char *outfile = argv[2];
  int buffer;
  int i = 0;  
  int fi = open(infile, O_RDONLY); 
  int fo = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
  
  assert(fo > -1 && fi > -1); /* exit if open() failed */
 
  struct stat buf; 
  fstat(fi, &buf); 
  int size = buf.st_size; 
  int *p = malloc(size); 
 
  /* Reads all the lines of the infile to buffer*/
  while(read(fi, &buffer, sizeof(int)))
  {
    *(p + i) = buffer; 
    i++;
  }
  /* Writes all the lines in the buffer to the outfile in reverse order*/
  for(i = (size / 4) - 1; i >= 0; i--)
  {
   
    write(fo, (p + i), sizeof(int));

  }
 
    if ( close(fi) == -1 ) {
        fprintf(stderr, "error closing file -- quitting");
	exit(1);
    if ( close(fo) == -1 ) {
        fprintf(stderr, "error closing file -- quitting");
	exit(1);

  return 0;
}
