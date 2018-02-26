typedef unsigned long ulong;

typedef enum stack_error_codes
{
	STACK_OK = 0,
	STACK_BIG_COUNT,
} stack_error_code;

typedef enum stack_status_codes
{
	STACK_EMPTY = 100,
	STACK_FULL
} stack_status_code;

template <typename Type, ulong Size>
class stack
{
	private:
	Type data[Size];
	ulong count;
	template <typename T>
	T check();
	
	public:
	stack();
	~stack();
	
	stack_error_code push(Type value);
	Type pop();
	void dump();
	
};
