#include <iostream>
#include <fstream>

class Reader
{

public:

	virtual char Read() = 0;
	virtual char Write(char c) = 0;
	virtual void SetPosition(int pos) = 0;


};

