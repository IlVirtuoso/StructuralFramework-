#include "Streams.hpp"
#include "FileSystem.hpp"
int main() {
	using namespace Structural::Streams;
	using namespace Structural::FileSystem;
	BufferedFileReader fileReader{ "C:\\Users\\matte\\Desktop\\esTWEBXML.txt" };
	std::cout << fileReader.ReadAll() << std::endl;
	std::cout << fileReader.Size() << std::endl;
	File file{ "C:\\Users\\matte\\Desktop\\esTWEBXML.txt",OpenModes::READ};
	std::cout << file.isDir() << std::endl;
	
}