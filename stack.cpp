#include <cassert>
#include <iostream>
#include "stack.hpp"
//~ #include "stack_utilities.cpp"

#define STACK_INT_POISON -666666

template <typename T, ulong Size>
Stack <T, Size>::Stack():
count(0)
{
	for (ulong i = 0; i < Size; i++)
		data[i] = STACK_INT_POISON;
}

template <typename T, ulong Size>
Stack <T, Size>::~Stack()
{
	for (ulong i = 0; i < Size; i++)
		data[i] = STACK_INT_POISON;
}

template <typename T, ulong Size>
stack_error_code Stack <T, Size>::push(T value)
{
	if (check() == STACK_FULL)
	{
		std::cout << "PUSHING TO FULL STACK\n";
		return STACK_PUSH_TO_FULL_STACK;
	}
	data[count++] = value;
	return STACK_OK;
}

template <typename T, ulong Size>
T Stack <T, Size>::pop()
{
	if (check() == STACK_EMPTY)
	{
		std::cout << "POP FROM EMPTY STACK\n";
		return STACK_INT_POISON;
	}
	count--;
	T result = data[count];
	data[count] = STACK_INT_POISON;
	return result;
}

template <typename T, ulong Size>
stack_error_code Stack <T, Size>::check()
{
	if (count == Size) return STACK_FULL;
	if (count == 0) return STACK_EMPTY;
	return STACK_OK;
}

template <typename T, ulong Size>
void Stack <T, Size>::dump()
{
	//~ std::cout << "Stack dump [" << error_code_to_string(check())  << "]\n";
	std::cout << "{\n	count	= " << count << "\n";
	std::cout << "	data:\n";
	for (ulong i = 0; i < Size; i++)
		if (data[i] != STACK_INT_POISON)
			std::cout << "	data[" << i << "]	= " << data[i] << "\n";
	std::cout << "}\n\n"; 
}

