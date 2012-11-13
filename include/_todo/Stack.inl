//=============================================================================
// Implementation
//=============================================================================
/**
* Constructor
*/
template<typename T>
Stack<T>::Stack(unsigned int size)
    : pos(0), size(size)
{
    arr = new T[size];
}

/**
* Destructor
*/
template<typename T>
Stack<T>::~Stack()
{
    delete[] arr;
    arr = 0;
}

/**
* Push a element on stack
*/
template<typename T>
void Stack<T>::push(T elem)
{
    if(pos >= size)
        throw cul::Exception("cul stack overflow");
    
    arr[++pos] = elem;
}

/**
* Pops a element from stack
*/
template<typename T>
T Stack<T>::pop()
{
    if(pos <= 0)
        throw cul::Exception("cul stack underflow");
    
    return arr[pos--];
}