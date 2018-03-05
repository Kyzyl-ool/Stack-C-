#include <cassert>
#include <iostream>
#define STACK_INT_POISON -666666

typedef unsigned long ulong;

typedef enum stack_error_codes
{
	STACK_OK = 0,
	STACK_FULL,
	STACK_EMPTY,
	STACK_PUSH_TO_FULL_STACK,
} stack_error_code;

template <typename T = int, ulong Size = 128>
class Stack
{
private:
	T data[Size];
	ulong count;

public:	
	Stack();
	~Stack();
	
	stack_error_code push(T value);
	T pop();
	void dump();
	stack_error_code check();
};

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

