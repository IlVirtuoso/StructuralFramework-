#include <iostream>

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


		class BufferedFileReader : Reader {
			FILE* file;
			char* buffer = NULL;
			int pointer = 0;
			bool endOfFile = false;
			

		public:
			BufferedFileReader(std::string path);
			BufferedFileReader(FILE * file);
			std::string ReadLine();
			std::string ReadAll();
			char Read() override;
			void SetPosition(int pos) override;

		};

		

	}
}