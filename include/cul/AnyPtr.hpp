/*
    C++ Utility Library

    Copyright (c) 2010  okard
                  2010  Francis Xavier Joseph Pulikotil

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
#ifndef __CUL_ANYPTR_HPP__
#define __CUL_ANYPTR_HPP__

//Modified version from http://www.gamedev.net/reference/programming/features/TypeSafeGenPtr/

namespace cul {

/**
* AnyPtr Class
*/
class AnyPtr
{
private:
    ///pointer to object
    const void *_pObject;
    
    ///type id
    int         _typeId;
    
public:
    /**
    * Default Constructor
    */
    AnyPtr() :
        _pObject( 0 ),
        _typeId( 0 )
    {
    }

    /**
    * Construct from object pointer
    */
    template <class T>
    AnyPtr(T *const pObject) :
        _pObject( pObject ),
        _typeId( TypeId<T>() )
    {
    }

    /**
    * Copy Constructor
    */
    AnyPtr(const AnyPtr &other) :
        _pObject( other._pObject ),
        _typeId( other._typeId )
    {
    }

    /**
    * Assignment Operator
    */
    const AnyPtr &operator =(const AnyPtr &other)
    {
        _pObject = other._pObject;
        _typeId  = other._typeId;
        return (*this);
    }

    /**
    * Assign from object pointer
    */
    template <class T>
    const AnyPtr &operator =(T *const pObject)
    {
        _pObject = pObject;
        _typeId  = TypeId<T>();
        return (*this);
    }

    /**
    * Implicit cast to non-const object pointer
    */
    template <class T>
    operator T *const() const
    {
        if( _typeId == TypeId<T>() )
            return static_cast<T *const>( const_cast<void *const>(_pObject) );

        return 0;
    }

    /**
    * Implicit cast to const object pointer
    */
    template <class T>
    operator const T *const() const
    {
        if( (_typeId == TypeId<const T>()) || (_typeId == TypeId<T>()) )
            return static_cast<const T *const>( _pObject );

        return 0;
    }

private:
    /**
    * Id Generator Function
    */
    static const int GenerateId()
    {
        static int id = 0;
        return ++id;
    }

    /**
    * TypeID Generator Function
    */
    template <class T>
    static const int TypeId()
    {
        static const int typeId = GenerateId();
        return typeId;
    }
};

} //end namespace cul

#endif /* __CUL_ANYPTR_HPP__ */