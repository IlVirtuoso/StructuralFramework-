// CompliantFramework.cpp: definisce il punto di ingresso dell'applicazione.
//
#define EXPORT 1
#include "Core.h"
#include "Collections.hpp"
#include "ISerializable.hpp"
using namespace std;
using Structural::Collections::Generic::Dictionary;
using Structural::Collections::Generic::Array;
using namespace Structural;
int main()
{
	Array<int>* arr = new Array<int>({ 3,2,1,4,10,100,1000 });
	int (*fcn)() {0};
	auto sorted = arr->Select(Structural::Predicate<int>([](int a) {return a >= 10; }));
	for each (auto v in sorted)
	{
		std::cout << v << std::endl;
	}
}


