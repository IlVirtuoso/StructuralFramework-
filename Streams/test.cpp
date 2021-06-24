#include "Streams.hpp"
int main() {
	using namespace Structural::Streams;
	BufferedFileReader fileReader{ "C:\\Users\\matte\\Desktop\\esTWEBXML.txt" };
	std::cout << fileReader.ReadAll() << std::endl;
	std::cout << fileReader.Size() << std::endl;
	
}