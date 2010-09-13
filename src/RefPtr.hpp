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

#ifndef __REFPTR_HPP__
#define __REFPTR_HPP__

namespace cul
{

/**
* \brief Reference Counted Smart Pointer
*/
template<class T> class RefPtr
{
     //NOTICE: not thread safe
    typedef unsigned int uint;
   
    protected:
        ///object to store
        T* obj;
        /// reference count
        uint* count;

    public:
        /**
        * Constructor
        */
        RefPtr() : obj(0), count(0) {}

        /**
        * Constructor
        */
        RefPtr(T* nobj) : obj(nobj), count(new uint(1)) {}

        /**
        * Constructor
        */
        RefPtr(const RefPtr<T>& rp)  : obj(rp.obj), count(rp.count) { (*count)++; }

        /**
        * Destructor
        */
        ~RefPtr()
        {
            if(isUnique())
                del();
            else if(!this->isNull())
                (*count)--;
        }

        /**
        * Assign Operator
        */
        RefPtr<T>& operator = (T* nobj)
        {
            if(isUnique())
                del();
            else if(!isNull())
                (*count)--;

            obj=nobj;
            count = new uint(1);

            return *this;
        }

        /**
        * Assign Operator
        */
        RefPtr<T>& operator = (const RefPtr<T>& rp)
        {
            if(isUnique())
                del();
            else if(!isNull())
                (*count)--;

            obj = rp.obj;
            count = rp.count;
            (*count)++;

            return *this;
        }

        /**
        * is null
        */
        bool isNull() const   { return obj == 0 || count == 0 || (*count) == 0;  }
        
        /**
        * last one, is unique
        */
        bool isUnique() const { return !isNull() && (*count) == 1; }
        
        /**
        * reference count
        */
        uint refcount() const { return count == 0 ? 0 :(*count);}

        //TODO add exception
        
        /**
        * -> Operator Access
        */
        const T* operator->() const  { return obj; }
        
        /**
        * * Operator Access
        */
        T& operator * () const       { return (*obj);}


        private:
            ///clear internal objects
            inline void del()
            {
                //assert(unique());
                delete obj; obj = 0;
                delete count; count = 0;
            }
};

}; //end namespace cul


#endif // __REFPTR_HPP__
