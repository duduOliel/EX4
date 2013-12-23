#include "IllegalArgumentException.h"

IllegalArgumentException::~IllegalArgumentException(void)
{
}

ostream& operator<<(ostream& out, const IllegalArgumentException& obj)
{
	return out<<obj._msg;
}