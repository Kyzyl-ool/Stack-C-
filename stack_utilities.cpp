const char* error_code_to_string(stack_error_code code)
{
	#define _RET_CODE(code) case code: return #code;
	switch (code)
	{
		_RET_CODE(STACK_OK)
		default: return "STACK_UNKNOWN_ERROR";
	}
	
	#undef _RET_CODE
}
