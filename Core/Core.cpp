// CompliantFramework.cpp: definisce il punto di ingresso dell'applicazione.
//
#define EXPORT 1
#include "Core.h"
#include "Collections.hpp"
#include "ISerializable.hpp"
using namespace std;
using Structural::Collections::Generic::Dictionary;
int main()
{
	Dictionary<int, int>* dic = new Dictionary<int, int>();
	return 0;
}
