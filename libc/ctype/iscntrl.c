#include <ctype.h>

int (iscntrl)(int c)
	{
	return (_Ctype[c] & (_BB|_CN));
	}