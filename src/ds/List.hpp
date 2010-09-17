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
 
#ifndef __LIST_HPP__
#define __LIST_HPP__

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
        unsigned int count();
        
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
        
        //->
        //.
        //cast operator
        
};

/*
ListIterator<int> li(list);
while(li.next())
    std::cout << li << std:.endl;

for(ListIterator<int> li(list); li.hasNext(); li.next())

*/

} //end namespace ds
} //end namespace cul

#endif /* __LIST_HPP__ */