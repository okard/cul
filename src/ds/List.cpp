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

#include "List.hpp"

//because of stupidness of c++ this file need to be included
//so explicit namespace here
namespace cul {
namespace ds {
    
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
    return current->data;
}

 
} //end namespace ds
} //end namespace cul