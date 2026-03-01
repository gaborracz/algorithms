#include "queue.h"
#include <iostream>

int main()
{
  Queue<int> intQueue;

  for (int i = 0; i < 32; i++)
  {
    intQueue.add(i);
  }

  std::cout << "First element in the queue: " << intQueue.first() << std::endl;
  std::cout << "Queue size is: " << intQueue.getLength() << std::endl;
  std::cout << "Queue capacity is: " << intQueue.getCapacity() << std::endl;
  std::cout << "Queue start position is: " << intQueue.getStartPos() << std::endl;

  while (!intQueue.isEmpty())
  {
    std::cout << intQueue.rem() << std::endl;
  }

  Queue<int> intQueue2;

  intQueue2.add(1);
  intQueue2.add(2);
  intQueue2.add(3);

  std::cout << "Queue2 start position is: " << intQueue2.getStartPos() << std::endl;
  
  intQueue2.rem();

  std::cout << "Queue2 start position is: " << intQueue2.getStartPos() << std::endl;

  intQueue2.rem();
  intQueue2.rem();

  std::cout << "Queue2 start position is: " << intQueue2.getStartPos() << std::endl;

  intQueue2.setEmpty();
  std::cout << "Queue size is: " << intQueue.getLength() << std::endl;
  std::cout << "Queue capacity is: " << intQueue.getCapacity() << std::endl;
  std::cout << "Queue start position is: " << intQueue.getStartPos() << std::endl;
}
