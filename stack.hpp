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
