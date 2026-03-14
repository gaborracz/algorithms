#ifndef S1L_H
#define S1L_H

#include <iostream>

template <typename T>
class S1L
{
private:
  T m_key;
  S1L<T>* m_next;

public:
  S1L() : m_key{}, m_next{nullptr} {}

  S1L(T key) : m_key{key}, m_next{nullptr} {}

  bool insert(T& newNode, T key)
  {
    T* ptr{newNode};
    T* ptrPrev{nullptr};

    while ( ptr != nullptr && ptr->key!= key )
    {
      ptrPrev = ptr;
      ptr = ptr->m_next;
    }

    if ( ptr != nullptr )
    {
      return false;
    }

    S1L<T> q{new S1L<T>()};
    q->key = key;

    if ( ptrPrev == nullptr )
    {
      newNode = q;
    }

    ptrPrev->next = q;

    return true;
  }

  void print()
  {
    std::cout << "[ " << m_key << " ]" << std::endl;

    T* p = m_next;
    while ( p != nullptr )
    {
      std::cout << " --> [ " << m_key << " ]";
      p = p->next;
    }
  }
};

#endif
