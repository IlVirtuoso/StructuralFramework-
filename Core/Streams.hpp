#include <iostream>
#include <fstream>

namespace Structural {
	namespace Streams {
		
		class Reader
		{

		public:

			virtual char Read() = 0;
			virtual void SetPosition(int pos) = 0;

		};

		class Writer {
		public:
				virtual void Write(char c) = 0;
				virtual void SetPosition(int pos) = 0;
		};


		class FileReader : Reader {
			std::ifstream file;

		public:
			FileReader(std::string path);
			FileReader(std::ifstream file);

			std::string ReadLine();
			std::string ReadAll();


		};

		

	}
}