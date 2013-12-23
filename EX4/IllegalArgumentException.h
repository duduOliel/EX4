#pragma once
#include <iostream>
#include <string>
using namespace std;

class IllegalArgumentException
{
private:
	string _msg;
public:
	IllegalArgumentException(string msg) {_msg = msg;}
	~IllegalArgumentException(void);

	string getMessage() const {return _msg;}

	friend ostream& operator<<(ostream& out, const IllegalArgumentException& obj);
};

