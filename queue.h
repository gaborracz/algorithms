#ifndef QUEUE_H
#define QUEUE_H

#include <memory> // for allocator and allocator_traits
#include <utility> // for std::move()
#include <stdexcept> // for std::out_of_range()

template <typename T>
class Queue
{
private:
  using Traits = std::allocator_traits<std::allocator<T>>;

  T* m_data;
  int m_size;
  int m_capacity;
  int m_startPos;
  std::allocator<T> m_alloc;

  void increaseSize()
  {
    int newCapacity = m_capacity * 2;
    T* newQueue = Traits::allocate(m_alloc, newCapacity);

    for (int i = 0; i < m_size; i++)
    {
      Traits::construct(m_alloc, newQueue + i, std::move(m_data[(m_startPos + i) % m_capacity]));
      Traits::destroy(m_alloc, m_data + ((m_startPos + i) % m_capacity));
    }

    Traits::deallocate(m_alloc, m_data, m_capacity);

    m_data = newQueue;
    m_capacity = newCapacity;
    m_startPos = 0;
  }

public:
  // Disable copy constructor.
  Queue(const Queue& other) = delete;

  // Disable copy assignment operator.
  Queue& operator=(const Queue other) = delete;

  // Constructs an empty queue.
  Queue()
    : m_size{0}
    , m_capacity{16}
    , m_startPos{0}
  {
    m_data = Traits::allocate(m_alloc, m_capacity);
  }

  // Destruct the queue object.
  ~Queue()
  {
    for (int i = 0; i < m_size; i++)
    {
      Traits::destroy(m_alloc, m_data + ((m_startPos + i) % m_capacity));
    }

    Traits::deallocate(m_alloc, m_data, m_capacity);
  }

  // Join an element to the end of the queue.
  void add(const T& newElement)
  {
    if (m_capacity == m_size ) { increaseSize(); }

    Traits::construct(m_alloc, m_data + ((m_startPos + m_size) % m_capacity), newElement);
    m_size++;
  }

  // Remove and return the first element of the queue.
  T rem()
  {
    if (m_size == 0) { throw std::out_of_range("Queue::rem(): queue is empty."); }

    T value = std::move(m_data[m_startPos]);
    Traits::destroy(m_alloc, m_data + m_startPos);
    m_startPos = (m_startPos + 1) % m_capacity;
    m_size--;

    return value;
  }

  // Return the first element of the queue.
  T first() const
  {
    if (m_size == 0) { throw std::out_of_range("Queue::first(): queue is empty."); }

    return m_data[m_startPos];
  }

  void setEmpty()
  {
    for (int i = 0; i < m_size; i++)
    {
      Traits::destroy(m_alloc, m_data + ((m_startPos + i) % m_capacity));
    }

    m_startPos = 0;
    m_size = 0;
  }

  int getLength() const { return m_size; }

  int getCapacity() const { return m_capacity; }

  int getStartPos() const { return m_startPos; }

  bool isEmpty() { return m_size == 0; }
};

#endif
