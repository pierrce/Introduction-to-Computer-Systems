#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  char *string;
  struct node *next;
} Node;

char *pop(Node **stack){

  if((*stack) != NULL){
    Node *sHolder = *stack;
    char *value = sHolder->string;
    *stack = sHolder->next;
    return value;
  }

  else{
    return NULL;
  }

}

Node *push(Node *stack, char *pInteger){

  if(stack == NULL){
  Node *sHolder = malloc(sizeof(Node));
  sHolder->string = pInteger;
  sHolder->next = NULL;
  stack = sHolder;
  return stack;
  }

  else{
    Node *sHolder = malloc(sizeof(Node));
    sHolder->string = pInteger;
    sHolder->next = stack;
    stack = sHolder;
    return stack;
  }

}

int main(int argc, char *argv[]){

  if (argc != 3) {
    fprintf(stderr, "usage: strrev <inputfile> <outputfileInt> <outputfileString>\n");
    exit(1);
  }

  char *infile = argv[1]; 
  char *outfile = argv[2]; 
  FILE *fi = fopen(infile, "r"); 
  FILE *fo = fopen(outfile, "w"); 
  Node *stack; 
  stack = NULL;
  int i, count = 0;
  

  while( 1 ){
    char* pInteger = malloc(10);
    if (fgets(pInteger, 10, fi) == NULL){
      break;
    }
    stack = push(stack, pInteger);
    count++;
  }

  for(i = count; i > 0; i--){
    char* pInteger = pop(&stack);
    fprintf(fo, "%s", pInteger);
  }

  fclose(fi);
  fclose(fo);
  return 0;
}
