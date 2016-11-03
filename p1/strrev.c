/* Assignment1 strrev
 * by Alec Pierce, Lecture 2 and Dan Hayes, Lecture 1
 * September 25, 2014
 *
 * The program takes an input .str file and
 * creates an output .str file which is the
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

typedef struct node
{
  char *string;
  struct node *next;
} Node;

/* 
 * Removes an int value in String form from the stack.
 *
 */
char *pop(Node **stack)
{

  if((*stack) != NULL)
  {
    Node *sHolder = *stack;
    char *value = sHolder->string;
    *stack = sHolder->next;
    return value;
  }

  else
  {
    return NULL;
  }

}

/* 
 * Adds an int value in String form to the stack.
 *
 */
Node *push(Node *stack, char *pInteger)
{

  if(stack == NULL)
  {
  Node *sHolder = malloc(sizeof(Node));
  sHolder->string = pInteger;
  sHolder->next = NULL;
  stack = sHolder;
  return stack;
  }

  else
  {
    Node *sHolder = malloc(sizeof(Node));
    sHolder->string = pInteger;
    sHolder->next = stack;
    stack = sHolder;
    return stack;
  }

}

int main(int argc, char *argv[])
{

  if (argc != 3) 
  {
    fprintf(stderr, "usage: strrev <inputfile> <outputfile>\n");
    exit(1);
  }

  char *infile = argv[1]; 
  char *outfile = argv[2]; 
  FILE *fi = fopen(infile, "r"); 
  FILE *fo = fopen(outfile, "w"); 
  Node *stack; 
  stack = NULL;
  int i, count = 0;
  

  while( 1 )
  {
    char* pInteger = malloc(10);
    if (fgets(pInteger, 10, fi) == NULL){
      break;
    }
    stack = push(stack, pInteger);
    count++;
  }

  for(i = count; i > 0; i--)
  {
    char* pInteger = pop(&stack);
    fprintf(fo, "%s", pInteger);
  }

  fclose(fi);
  fclose(fo);
  return 0;
}




