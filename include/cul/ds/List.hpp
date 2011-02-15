/*
    C++ Utility Library

    Copyright (c) 2010  okard

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/
 
#ifndef __CUL_LIST_HPP__
#define __CUL_LIST_HPP__

namespace cul {
namespace ds {

//forward declaration
template<typename T>
class ListIterator;

/**
* Double Linked List
*/
template<typename T>
class List
{
    friend class ListIterator<T>;
    
    private:
        ///Node Structure
        struct Node
        {
            T data;
            Node* next;
            Node* prev;
        };
        
        ///List head element
        Node* head;
        
        ///List tail element
        Node* tail;
        
        ///count of elements
        unsigned int pCount;
        
    public:
        /**
        * Constructor
        */
        List();
        
        /**
        * Destructor
        */
        ~List();
        
        /**
        * add element to list
        */
        T add(T obj);
        
        /**
        * remove element from list
        */
        void remove(T obj);
        
        
        /**
        * Count of elements in list
        */
        unsigned int count() const;
        
    private:
        /**
        * Remove nodes
        */
        void remove(Node* nod);
        
        /**
        * New node
        */
        Node* newNode();
        
};

/**
* Double Linked List Iterator
*/
template<typename T>
class ListIterator
{
    private:
        //the list
        const List<T>& list;
        //current node
        typename List<T>::Node* current;
        
    public:
        /**
        * Constructor
        */
        ListIterator(const List<T>& list);
        
        //TODO reset
        
        /**
        * next item
        */
        bool next();
        
        /**
        * has next
        */
        bool hasNext();
        
        /**
        * prev item
        */
        bool prev();
        
        /**
        * has prev
        */
        bool hasPrev();
        
        //TODO T ->
        //TODO T .
        //TODO T value()
        
        
        /**
        * cast operator
        */
        operator T ();     
};

/*
ListIterator<int> li(list);
while(li.next())
    std::cout << li << std:.endl;

for(ListIterator<int> li(list); li.hasNext(); li.next())

*/

//=============================================================================
// Implementation
//=============================================================================

/**
* Constructor
*/
template<typename T>
List<T>::List()
    : head(0), tail(0), pCount(0)
{
}

/**
* Destructor
*/
template<typename T>
List<T>::~List()
{
}

/**
* Add element
*/
template<typename T>
T List<T>::add(T obj)
{
    //empty list
    if(head  == 0 && tail == 0)
    {
        head = tail = newNode();
        head->data = obj;
        pCount++;
        return obj;
    }
    
    //add
    Node* n = newNode();
    n->data = obj;
    n->prev = tail;
    tail->next = n;
    tail = n;
    
    //++ count
    pCount++;
    
    return obj;
}

/**
* remove element from list
*/
template<typename T>
void List<T>::remove(T obj)
{
}

/**
* Count of elements in list
*/
template<typename T>
unsigned int List<T>::count() const
{
    return pCount;
}

/**
* remove node
*/
template<typename T>
void List<T>::remove(Node* nod)
{
}

/**
* New node
*/
template<typename T>
typename List<T>::Node* List<T>::newNode()
{
    Node* n = new Node();
    n->prev = 0;
    n->next = 0;
}


/**
* Create ListIterator
*/
template<typename T>
ListIterator<T>::ListIterator(const List<T>& list)
    : list(list), current(0)
{
}

/**
* next item
*/
template<typename T>
bool ListIterator<T>::next()
{
    //fix
    if(current == 0 && list.count() > 0)
    {
        current = list.head;
        return true;
    }
    
    if(current != 0 && current->next != 0)
    {
        current = current->next;
        return true;
    }
    
    if(current != 0 && current->next == 0)
        return false;
    
    return false;
}
        
/**
* has next
*/
template<typename T>
bool ListIterator<T>::hasNext()
{
    if(current == 0 && list.count() > 0)
        return true;
    
    if(current == 0 && list.count() == 0)
        return false;
    
    if(current != 0)
        return current->next != 0;
        
    return false;
}
        
/**
* prev item
*/
template<typename T>
bool ListIterator<T>::prev()
{
    return false;
}
     
/**
* has prev
*/
template<typename T>
bool ListIterator<T>::hasPrev()
{
    if(current == 0 && list.count() > 0)
        return true;
    
    if(current == 0 && list.count() == 0)
        return false;
    
    if(current != 0)
        return current->prev != 0;
        
    return false;
}

/**
* Cast Operator
*/
template<typename T>
ListIterator<T>::operator T ()
{
    //in for loops it is required to load the first element at access
    if(current == 0)
        current = list.head;
    
    return current->data;
}


} //end namespace ds
} //end namespace cul

#endif /* __CUL_LIST_HPP__ */