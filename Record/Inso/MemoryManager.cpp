#include <stdio.h>
#include <string>
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
    // std::cout<<"initializeMemoryManager"<<std::endl;
    for(int i=0;i<MM_POOL_SIZE;i++){
      MM_pool[i] = 0;
    }
  }

  // return a pointer inside the memory pool
  // If no chunk can accommodate aSize call onOutOfMemory()
  void* allocate(int aSize)
  {
    // TODO: IMPLEMENT ME
    std::cout<<"allocate:"<<aSize<<std::endl;
    if(aSize+5+1>freeRemaining()){
      onOutOfMemory();
    }

    // mark started position
    int i=0,k=0;
    for(k=0;k<MM_POOL_SIZE;k++){

      for(i=k;i<MM_POOL_SIZE;i++){
        // char to int
        int temp = 0;
        for(int j = 0;j<5;j++){
          if ((MM_pool[i+j] < '0') || (MM_pool[i+j] > '9')){
                 break;
          }
          temp = temp * 10 + (MM_pool[i+j] - '0'); 
        }
        if (temp ==0){
          break;
        }
        else{
          i += 5;
          i += temp;
        }
      }
      // std::cout<<"allocate started position: "<<i<<std::endl;


      if(i==MM_POOL_SIZE||i+aSize+5+1>MM_POOL_SIZE){
        onOutOfMemory();
      }

      // test if there're enough space
      int test;
      for(test = aSize+5+1;test>=0;test--){
        if(MM_pool[i+test]!=0) break;
      }

      if(test<0){ // space is enough
          // int to char
          // store the size
          std::cout<<"allocate started position: "<<i<<std::endl;
          int temp=aSize;
          int j;
          if(temp<10){j=1;}
          else if (temp<100){j=2;}
          else if (temp<1000){j=3;}
          else if (temp<10000){j=4;}
          else {j=5;}
          // std::cout<<"temp: "<<temp<<" j: "<<j<<std::endl;
          while (j>0)
          {
              int rem = temp % 10;
              MM_pool[i+j-1] = rem+'0';
              // std::cout<<" j: "<<j<<" "<<MM_pool[i+j-1]<<std::endl;
              temp = temp/10;
              j--;
          }
          // for(j=0;j<5;j++){
          //   std::cout<<MM_pool[i+j];
          // }
          // std::cout<<std::endl;
          // get the address of memory pool
          i += 5;
          return ((void*) &MM_pool[i]);
          // std::cout<<"memory position: "<<i<<std::endl;   
        }
      else{
        i += test + 2;
      }
    }
  }

  // Free up a chunk previously allocated
  void deallocate(void* aPointer)
  {
    // TODO: IMPLEMENT ME

    // mark the started position
    int start = (char*)aPointer - MM_pool;
    start -= 5;
    // std::cout<<"started position: "<<start<<std::endl;

    // char to int
    int temp = 0;
    for(int j = 0;j<5;j++){
        if ((MM_pool[start+j] < '0') || (MM_pool[start+j] > '9')){
               break;
        }
        temp = temp * 10 + (MM_pool[start+j] - '0'); 
    }
    int delta = 5+temp+1;
    // std::cout<<"delta: "<<delta<<std::endl;

    int i;
    for(i=start;i<delta;i++){
      MM_pool[i] = 0;
    }
  }

  //---
  //--- support routines
  //--- 

  // Will scan the memory pool and return the total free space remaining
  int freeRemaining(void)
  {
    // TODO: IMPLEMENT ME
    // std::cout<<"freeRemaining"<<std::endl;
    int i=0;
    int mem = 0;
    // mark started position
    for(i=0;i<MM_POOL_SIZE;i++){
      if(MM_pool[i]==0){
        continue;
      }

      // char to int
      int temp = 0;
      for(int j = 0;j<5;j++){
        if ((MM_pool[i+j] < '0') || (MM_pool[i+j] > '9')){
               break;
        }
        temp = temp * 10 + (MM_pool[i+j] - '0'); 
      }

      i += 5;
      i += temp;

      mem += 5+temp+1; 
      // std::cout<<"mem: "<<mem<<std::endl;
    }

    // std::cout<<"started position: "<<i<<std::endl;

    return (MM_POOL_SIZE-mem-5-1);
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