// CompliantFramework.cpp: definisce il punto di ingresso dell'applicazione.
//
#define EXPORT 1
#include "CompliantFramework.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}

int Test() { printf("Hello dll"); return 0; }