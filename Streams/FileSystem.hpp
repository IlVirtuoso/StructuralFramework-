#include <iostream>

namespace Structural {

	
	

	namespace FileSystem {
		enum OpenModes : char {
			READ = 'r',
			READWRITE = 'rw',
			WRITE = 'w',
			WRITEAPPEND = 'a+',
		};

		class File {
			std::string path;
			FILE* file;
			struct stat* st;
		public:
			File(std::string path, OpenModes openMode);
			bool isFile();
			bool isDir();
			bool isSocket();
			bool isPipe();
		};
	}
}