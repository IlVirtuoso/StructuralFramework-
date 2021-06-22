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
	
	Dictionary<string, int> dict{};
	dict.Insert("Henlo", 10);
	cout << dict["Henlo"] << endl;
	dict.Remove("Henlo");
	cout << dict["Henlo"] << endl;
}


