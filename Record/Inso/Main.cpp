

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>

#include "MemoryManager.h"

int main(void)
{
  using namespace MemoryManager;

  initializeMemoryManager();

  long* int_pointer;
  char* string_pointer;

  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree() << std::endl;

  int_pointer = (long *) allocate(sizeof(long));
  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;
  string_pointer = (char*) allocate(255);

  *int_pointer = 0xDEADBEEF; //set the pointer to null
  strcpy(string_pointer,"It was the best of times, it was the worst of times");

  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;

  deallocate(int_pointer);
  
  // test case
  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;
  char *test_pointer1,*test_pointer2,*test_pointer3,*test_pointer4;
  test_pointer1 = (char*) allocate(8);
  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;
  test_pointer4 = (char*) allocate(3);
  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;
  // test_pointer3 = (char*) allocate(largestFree());
  test_pointer3 = (char*) allocate(freeRemaining()-10);
  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;
  test_pointer2 = (char*) allocate(3);
  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;
  deallocate(test_pointer4);
  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;
  deallocate(test_pointer3);
  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;

  deallocate(string_pointer);
  std::cout << "Free memory = " << freeRemaining() << " Largest = " << largestFree() << " Smallest = " << smallestFree()<< std::endl;
}

namespace MemoryManager
{
  void onOutOfMemory(void)
  {
    std::cerr << "Memory pool out of memory" << std::endl;
    exit( 1 );
  }

  // call for any other error condition, providing meaningful error messages are appreciated
  void onIllegalOperation(const char* fmt,...)
  {
    if ( fmt == NULL )
    {
      std::cerr << "Unknown illegal operation" << std::endl;
      exit( 1 );
    }
    else
    {
      char	buf[8192];

      va_list argptr;
      va_start (argptr,fmt);
      vsprintf (buf,fmt,argptr);
      va_end (argptr);

      std::cerr << "Illegal operation: \"" << buf << "\"" << std::endl;
      exit( 1 );
    }
  }
}

