#include "stack.cpp"

int main()
{
	Stack <int, 5> s;
	
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	
	s.dump();
	return 0;
}
