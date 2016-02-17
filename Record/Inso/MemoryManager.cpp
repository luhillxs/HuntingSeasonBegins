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
    if(aSize>freeRemaining()){
      onOutOfMemory();
    }
    else if(aSize>largestFree()){
      std::cerr<<"No suitable data block."<<std::endl;
      onOutOfMemory();
    }

    // mark started position
    int i=0,k=0;
    // k: travel the whole pool
    // i: jump over the occupied data block
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
          // std::cout<<"temp: "<<temp<<" i:"<<i<<std::endl;
        }
      }
      // std::cout<<"allocate possibly started position: "<<i<<std::endl;


      if(i==MM_POOL_SIZE||i+aSize>MM_POOL_SIZE){
        std::cerr<<"No suitable data block."<<std::endl;
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
          // std::cout<<"allocate size: ";
          // for(int count=0;count<5;count++){
          //   std::cout<<MM_pool[i+count];
          // }
          // std::cout<<std::endl;
          // get the address of memory pool
          i += 5;
          return ((void*) &MM_pool[i]);
          // std::cout<<"memory position: "<<i<<std::endl;   
        }
      else{ // space is not enough, then go find another emplty data block
        // travel back to mark the size of the occupied data block
        // int travel_back;
        // for(travel_back = i+test;MM_pool[travel_back]!=0&&travel_back>=0;travel_back--){
          
        // }
        // k = travel_back;
        int travel = i;
        while(MM_pool[travel+1]==0){
          travel++;
        }
        k = travel;
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
    std::cout<<"dellocate started position: "<<start<<std::endl;

    // char to int
    int temp = 0;
    for(int j = 0;j<5;j++){
        if ((MM_pool[start+j] < '0') || (MM_pool[start+j] > '9')){
               break;
        }
        temp = temp * 10 + (MM_pool[start+j] - '0'); 
    }
    int delta = 5+temp+1;
    std::cout<<"dellocate total elements: "<<delta<<std::endl;

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
        mem++;
        // std::cout<<"i: "<<i<<std::endl;
        continue;
        
      }
      // std::cout<<"mem ongoing:"<< mem <<std::endl;
      
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
      // std::cout<<"origin i:"<< i-temp-5<<" jump: "<<temp<<" i:"<<i<<std::endl;
      // std::cout<<"i: "<<i<<std::endl;
      // std::cout<<"MM_pool[i+1]: "<<(int)MM_pool[i+1]<<std::endl;
      // std::cout<<"mem: "<<mem<<std::endl;
    }
    // std::cout<<"mem ongoing:"<< mem <<std::endl;
    // std::cout<<"started position: "<<i<<std::endl;
    
    return (mem-5-1>0? mem-5-1:0);
  }

  // Will scan the memory pool and return the largest free space remaining
  int largestFree(void)
  {
    // TODO: IMPLEMENT ME
    // std::cout<<"largestFree"<<std::endl;
    int i=0;
    int mem = 0;
    int max_mem = 0;
    // mark started position
    for(i=0;i<MM_POOL_SIZE;i++){
      if(MM_pool[i]==0){
        mem++;
        continue;
      }
      // std::cout<<"mem: "<<mem<<std::endl;
      if(mem>max_mem){
        max_mem = mem;
        // std::cout<<"max_mem: "<<max_mem<<std::endl;
      }
      mem = 0;
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
    }
    
    if(mem>max_mem){
        max_mem = mem;
        // std::cout<<"max_mem: "<<max_mem<<std::endl;
    }

    return (max_mem-5-1>0? max_mem-5-1:0);
  }

  // will scan the memory pool and return the smallest free space remaining
  int smallestFree(void)
  {
    // TODO: IMPLEMENT ME
    int i=0;
    int mem = 0;
    int min_mem = MM_POOL_SIZE;
    bool reset = true;
    bool hasDebris = false;
    // mark started position
    for(i=0;i<MM_POOL_SIZE;i++){
      if(MM_pool[i]==0){
        mem++;
        reset = false;
        continue;
      }
      
      hasDebris = true;
      // std::cout<<"mem: "<<mem<<std::endl;
      if(mem<=min_mem&&!reset&&mem-5-1>0){
        min_mem = mem;
        // std::cout<<"max_mem: "<<max_mem<<std::endl;
      }
      mem = 0;
      reset = true;
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
    }
    
    if(mem<min_mem&&!reset&&mem-5-1>0){
        min_mem = mem;
        // std::cout<<"max_mem: "<<max_mem<<std::endl;
    }
    if(hasDebris&&min_mem==MM_POOL_SIZE){ // the pool has debris
      min_mem = 0;
    }

    return (min_mem-5-1>0? min_mem-5-1:0);
  }
 }