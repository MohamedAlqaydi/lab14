#if !defined (TABLESORTEDLIST_H)
#define TABLESORTEDLIST_H

#include "SortedListDoublyLinked.h"

template < class T >
class TableSortedList
{

   private:
      SortedListDoublyLinked<T>* sldl;

   public:
      TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item));
      ~TableSortedList();

      bool tableIsEmpty();
      int tableSize();
      T* tableRetrieve(String* sk);
      void tableInsert(T* item);  //does not allow duplicate search keys into the table (need to use getKey() to check for duplicates)
      bool tableRemove(String* search_key);  //returns true if delete is successful (need to call tableRetrieve to see if the item is there)

      ListDoublyLinkedIterator<T>* iterator();

};

//DO THIS
//complete the implementation for TableSortedList
template < class T >
TableSortedList<T>::TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item))
{
	sze = 0;
	sldl = new SortedListDoublyLinked<T>(comp_item, comp_key);
}

template < class T >
TableSortedList<T>::~TableSortedList()
{
	delete sldl;
}

template < class T >
bool TableSortedList<T>::tableIsEmpty()
{
	return sze = 0;
}

template < class T >
int TableSortedList<T>::tableSize()
{
	return sze;
}

template < class T >
T* TableSortedList<T>::tableRetrieve(String* sk)
{
	return sldl->get(sk);
}

template < class T >
void TableSortedList<T>::tableInsert(T* item)
{
	String* sk = item->getKey();
	T* found = sldl->get(sk);
	if (found == NULL)
	{
		sldl->add(item);
		sze++;
	}
}

template < class T >
bool TableSortedList<T>::tableRemove(String* search_key)
{
	bool success = 0;
	T* item = sldl->get(search_key);
	
	if(item != NULL)
	{
		sldl->remove(search_key);
		sze--;
		success = 1;
	}
	return success;
}

template < class T >
 ListDoublyLinkedIterator<T>* TableSortedList<T>::iterator()
{
	return sldl->iterator();
}


#endif
