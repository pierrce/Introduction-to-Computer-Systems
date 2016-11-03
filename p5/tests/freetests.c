/*Alec Pierce, Lecture 2*/
#include <assert.h>
#include <stdlib.h>
#include "mem.h"

int main(){

  assert(Mem_Init(4096) == 0);
  void* ptr[4];

  ptr[0] = Mem_Alloc(12);
  assert(Mem_Free(ptr[0]) == 0);
  
  ptr[0] = Mem_Alloc(12);
  assert(Mem_Free(NULL) == 0);
  assert(Mem_Free(ptr[0]+1) == 0);

  return(0);

}
