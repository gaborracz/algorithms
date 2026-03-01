#ifndef STACK_H
#define STACK_H

#include <memory>
#include <utility>
#include <stdexcept>

template <typename T>
class Stack
{
private:
  // Internal type alias for allocator_traits.
  using Traits = std::allocator_traits<std::allocator<T>>;

  // Member variables to store reference of the first element in the stack,
  // the current size of the stack and currrently available maximum capacity.
  T* m_data;
  int m_size;
  int m_capacity;

  // Member variable to create a standard stateless allocator.
  // Because allocator_traits methods are static an allocater instance
  // needs to be passed in when using them.
  std::allocator<T> m_alloc;

  // Helper function to increase the size of the Stack when it's full.
  void increaseSize()
  {
    // This implementation is similar to std::vector, size doubles
    // everytime the Stack is full and new element is being pushed.
    int newCapacity = m_capacity * 2;
    
    // Allocate allocator<T> times newCapacity of memory.
    T* newArray = Traits::allocate(m_alloc, newCapacity);
    
    for (int i = 0; i < m_size; i++)
    {
      // Create a shallow copy with std::move(), it is more
      // efficient if the stack contains bigger objects like std::string.
      Traits::construct(m_alloc, newArray + i, std::move(m_data[i]));
      Traits::destroy(m_alloc, m_data + i);
    }

    // Objects in the memory have already been destroyed at this point,
    // free up allocated memory space.
    Traits::deallocate(m_alloc, m_data, m_capacity);

    m_data = newArray;
    m_capacity = newCapacity;
  }

public:
  // Delete default copy constructor.
  Stack(const Stack& other) = delete;

  // Disable copy assignment operator.
  Stack& operator=(const Stack& other) = delete;

  // Constructs an empty Stack object with initial size of 0
  // and initial capacity of 16 elements.
  Stack()
    : m_size{0}
    , m_capacity{16}
  {
    m_data = Traits::allocate(m_alloc, m_capacity);
  }

  // Destructs the Stack object.
  ~Stack()
  {
    for(int i = 0; i < m_size; i++)
    {
      Traits::destroy(m_alloc, m_data + i);
    }

    // Deallocate memory by passing the first pointer
    // and the number of allocated elements.
    Traits::deallocate(m_alloc, m_data, m_capacity);
  }

  // Inserts a new element on top of the Stack.
  void push(T newElement)
  {
    if (m_size == m_capacity) { increaseSize(); }

    Traits::construct(m_alloc, m_data + m_size, newElement);
    m_size++;
  }

  // Returns and removes the top element of the Stack.
  T pop()
  {
    if (m_size == 0) { throw std::out_of_range("Stack<T>::pop(): stack is empty"); }

    m_size--;
    T value = std::move(m_data[m_size]);

    Traits::destroy(m_alloc, m_data + m_size);

    return value;
  }

  // Returns the top element of the Stack.
  T top() const
  {
    if (m_size == 0) { throw std::out_of_range("Stack<T>::top(): stack is empty"); }

    return m_data[m_size - 1];
  }

  bool isEmpty() { return m_size == 0; }

  void setEmpty()
  {
    for (int i = 0; i < m_size; i++) { Traits::destroy(m_alloc, m_data + i); }
    m_size = 0;
  }

  int getSize() const { return m_size; }
};

#endif
