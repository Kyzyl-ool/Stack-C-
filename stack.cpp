#include "stack.hpp"
#include <assert.h>

const int STACK_INT_POISON = -666666;

template <typename Type, ulong Size>
stack <Type, Size>::stack():
count(0)
{
	for (ulong i = 0; i < Size; i++)
		data[i] = STACK_INT_POISON;
}

template <typename Type, ulong Size>
stack <Type, Size>::~stack()
{
	count = 0;
	for (ulong i = 0; i < Size; i++)
		data[i] = STACK_INT_POISON;
}

template <typename Type, ulong Size>
template <typename T>
T stack <Type, Size>::check()
{
	if (count == Size) return STACK_FULL;
	if (count > Size) return STACK_BIG_COUNT;
	if (count == 0) return STACK_EMPTY;
	
	return STACK_OK;
}



template <typename Type, ulong Size>
stack_error_code stack <Type, Size>::push(Type value)
{
	assert(check() == STACK_FULL);
	data[count++] = value;
	return check();
}

template <typename Type, ulong Size>
Type stack <Type, Size>::pop()
{
	assert(check() == STACK_EMPTY);
	Type result = data[--count--];
	data[count] = STACK_INT_POISON;
	return result;
}
