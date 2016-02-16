#include <stdio.h>
#include <iostream>

#include "MemoryManager.h"



namespace MemoryManager
{
  // IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT 
  //
  // This is the only static memory that you may use, no other global variables may be
  // created, if you need to save data make it fit in MM_pool
  //
  // IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT


  const int MM_POOL_SIZE = 65536;
  char MM_pool[MM_POOL_SIZE];

  // Initialize set up any data needed to manage the memory pool
  void initializeMemoryManager(void)
  {
    // TODO : IMPLEMENT ME
    std::cout<<"initializeMemoryManager"<<std::endl;
    for(int i=0;i<MM_POOL_SIZE;i++){
      MM_pool[i] = 0;
    }
  }

  // return a pointer inside the memory pool
  // If no chunk can accommodate aSize call onOutOfMemory()
  void* allocate(int aSize)
  {
    // TODO: IMPLEMENT ME
    if(aSize+1>MM_POOL_SIZE){
      onOutOfMemory();
    }
    
    int i;
    for(i=0;i<MM_POOL_SIZE&&MM_pool[i]!=0;i++){
      
    }
    
    if(i==MM_POOL_SIZE||i+aSize+1>MM_POOL_SIZE){
      onOutOfMemory();
    }
    else{
      
    }
    
    return ((void*) 0);
  }

  // Free up a chunk previously allocated
  void deallocate(void* aPointer)
  {
    // TODO: IMPLEMENT ME
  }

  //---
  //--- support routines
  //--- 

  // Will scan the memory pool and return the total free space remaining
  int freeRemaining(void)
  {
    // TODO: IMPLEMENT ME
    int i;
    for(i=0;i<MM_POOL_SIZE&&MM_pool[i]!=0;i++){
      
    }
    return (MM_POOL_SIZE-i);
  }

  // Will scan the memory pool and return the largest free space remaining
  int largestFree(void)
  {
    // TODO: IMPLEMENT ME

    return 0;
  }

  // will scan the memory pool and return the smallest free space remaining
  int smallestFree(void)
  {
    // TODO: IMPLEMENT ME

    return 0;
  }
 }