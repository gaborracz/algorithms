#include <iostream>


template <typename T>
struct S1L
{
  T m_data;
  S1L* m_next{nullptr};
};

template <typename T>
// There is a sentinel element at the beginning of the list,
// must pass the list by reference.
bool insertS1L(S1L<T>* &list, T data)
{
  S1L<T>* pPrev{nullptr};
  S1L<T>* pCurrent{list};

  // Check if the list already contains the element we want to insert.
  while (pCurrent != nullptr && pCurrent->m_data != data)
  {
    pPrev = pCurrent;
    pCurrent = pCurrent->m_next;
  }

  // If pCurrent is not a null pointer the list already contains
  // the element, insert failed, early return.
  if (pCurrent != nullptr) { return false; }

  // New element is created and added to the list.
  // Reserve heap space and set the value.
  S1L<T>* newElement = new S1L<T>;
  newElement->m_data = data;

  // If previous element is a null pointer, the list is currently empty.
  // This will be the first element.
  if (pPrev == nullptr)
  {
    list = newElement;
  }
  else
  {
    // Otherwise append the new element to the end of the list.
    pPrev->m_next = newElement;
  }

  return true;
}

template <typename T>
bool deleteS1LE(S1L<T>* &list, T data)
{
  S1L<T>* pPrev{nullptr};
  S1L<T>* pCurrent{list};

  // Search the list for the matching element.
  while ( pCurrent != nullptr && pCurrent->m_data != data )
  {
    pPrev = pCurrent;
    pCurrent = pCurrent->m_next;
  }

  // There was no such element, nothing to delete.
  if ( pCurrent == nullptr ) { return false; }

  // If previous element is a null pointer, current element is the first element and it should be removed.
  if ( pPrev == nullptr )
  {
    // To remove the element referenced by pCurrent, when it's the first element
    // set the pointer to the second element in the list.
    list = pCurrent->m_next;
  }
  else
  {
    // To remove the element referenced by pCurrent set the previous
    // element's pointer to the next element after pCurrent.
    pPrev->m_next = pCurrent->m_next;
  }
  // Free up allocated heap space.
  delete pCurrent;

  return true;
}

// Cuts the list into two parts at the n element and return the second part.
template <typename T>
S1L<T>* cutS1L(S1L<T>* list, int n)
{
  S1L<T>* pCurrent = list;
  S1L<T>* pReturn = nullptr;

  if ( list == nullptr) { return pReturn; }
  
  while ( n > 1 )
  {
    n--;
    pCurrent = pCurrent->m_next;
  }

  pReturn = pCurrent->m_next;
  pCurrent->m_next = nullptr;

  return pReturn;
}

template <typename T>
void printS1L(const S1L<T>* it)
{
  if ( it == nullptr ) { std::cout << "Empty S1L..." << std::endl; }

  while ( it != nullptr )
  {
    if ( it->m_next == nullptr )
    {
      std::cout << it->m_data << std::endl;
    }
    else
    {
      std::cout << it->m_data << " --> ";
    }
    it = it->m_next;
  }
}

template <typename T>
void deleteS1L(S1L<T>* &list)
{
  S1L<T>* pPrev{nullptr};
  S1L<T>* pCurrent{list};

  while ( pCurrent != nullptr )
  {
    pPrev = pCurrent;
    pCurrent = pCurrent->m_next;

    delete pPrev;
  }

  list = nullptr;
}


int main()
{
  S1L<int>* simpleList = nullptr;

  printS1L(simpleList);

  insertS1L<int>(simpleList, 5);
  insertS1L<int>(simpleList, 5);
  insertS1L<int>(simpleList, 4);
  insertS1L<int>(simpleList, 1);

  printS1L(simpleList);

  deleteS1LE<int>(simpleList, 4);
  deleteS1LE<int>(simpleList, 5);

  printS1L(simpleList);

  printS1L(simpleList);
  
  S1L<int>* longList = nullptr;

  for ( int i = 1; i < 100; i++)
  {
    insertS1L<int>(longList, i);
  }

  printS1L(longList);

  S1L<int>* listPart = cutS1L(longList, 50);
  printS1L(listPart);
  printS1L(longList);

  deleteS1L(simpleList);
  deleteS1L(listPart);
  deleteS1L(longList);

  std::cout << "End of main..." << std::endl;
}
