const char* error_code_to_string(stack_error_code code)
{
	#define _RET_CODE(code) case code: return #code;
	switch (code)
	{
		_RET_CODE(STACK_OK)
		_RET_CODE(STACK_FULL)
		_RET_CODE(STACK_EMPTY)
		_RET_CODE(STACK_PUSH_TO_FULL_STACK)
		default: return "STACK_UNKNOWN_ERROR";
	}
	
	#undef _RET_CODE
}
