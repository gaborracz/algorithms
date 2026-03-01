#include <iostream>
#include <string>
#include "stack.h"

int main()
{
  Stack<int> intStack;
  std::cout << "intStack size is: " << intStack.getSize() << std::endl;
  std::cout << "size of size_t is: " << sizeof(size_t) << std::endl;

  intStack.push(1);
  std::cout << "intStack size is: " << intStack.getSize() << std::endl;
  std::cout << "Top element in the stack: " << intStack.top() << std::endl;

  /*
  Stack<int> biggerStack;
  for (int i = 1; i < 99; i++) { biggerStack.push(i); }
  std::cout << "biggerStack top element: " << biggerStack.top() << std::endl;

  while (!biggerStack.isEmpty())
  {
    std::cout << biggerStack.pop() << std::endl;
  }
  */

  Stack<std::string> wordStack;
  wordStack.push("Rings.");
  wordStack.push("the ");
  wordStack.push("of ");
  wordStack.push("Lord ");
  
  std::cout << wordStack.pop()
            << wordStack.pop()
            << wordStack.pop()
            << wordStack.pop()
            << std::endl;

  Stack<std::string> hugeStack;

  // This will use approx. 7G memory on macOS 26.2 
  for (int i = 0; i < 100000000; i++) { hugeStack.push("awesome"); }
}
