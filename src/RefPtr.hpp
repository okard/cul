/*
    C++ Utility Library
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

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
