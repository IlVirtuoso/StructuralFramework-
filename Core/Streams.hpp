#include <iostream>
#include <fstream>

namespace Structural {
	namespace Streams {
		
		class Reader
		{

		public:

			virtual char Read() = 0;
			virtual char Write(char c) = 0;
			virtual void SetPosition(int pos) = 0;

		};


	}
}