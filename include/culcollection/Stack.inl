//=============================================================================
// Implementation
//=============================================================================
/**
* Constructor
*/
template<typename T, size_t N>
Stack<T,N>::Stack()
    : pos_(0)
{
}

/**
* Destructor
*/
template<typename T, size_t N>
Stack<T,N>::~Stack()
{
}

/**
* Push a element on stack
*/
template<typename T, size_t N>
void Stack<T,N>::push(T elem)
{
    if(pos_ >= N)
        throw cul::Exception("cul stack overflow");
    
    arr_[++pos_] = elem;
}

/**
* Pops a element from stack
*/
template<typename T, size_t N>
T Stack<T,N>::pop()
{
    if(pos_ <= 0)
        throw cul::Exception("cul stack underflow");
    
    return arr_[pos_--];
}

/**
* Get Element at position
*/
template<typename T, size_t N>
const T& Stack<T,N>::operator[] (size_t idx) const
{
	if(idx > pos_ || idx < 0)
		throw cul::Exception("cul stack index out of bounds");

	return arr_[idx];
}
