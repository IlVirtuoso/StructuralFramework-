#include "Streams.hpp"

namespace Structural {

	namespace Streams {
		BufferedFileReader::BufferedFileReader(std::string path) {
			this->file = fopen(path.c_str(), "R");
			endOfFile = false;
		}

		BufferedFileReader::BufferedFileReader(FILE * file) {
			this->file = file;
			endOfFile = false;
		}

		char BufferedFileReader::Read() {
			char c;
			if (endOfFile) return -1;
			if (this->pointer == 0 && this->buffer == NULL) {
				this->buffer = new char[128];
				fgets(this->buffer, 128,this->file);
			}
			if (!endOfFile) {
				c = this->buffer[this->pointer];
				pointer++;
				if (c == -1)
					endOfFile = true;
				if (pointer == 128) {
					this->buffer = new char[128];
					pointer = 0;
				}
			}
			
		}

		std::string BufferedFileReader::ReadLine() {
			std::string str{};
			char c;
			while ((c = Read()) != -1 && c != '\n')
				str.push_back(c);
			return str;
		}

		void BufferedFileReader::SetPosition(int pos) {
			fseek(this->file, pos, 0);
		}

		std::string BufferedFileReader::ReadAll() {
			std::string str{};
			char c;
			while ((c = Read()) != -1)
				str.push_back(c);
			return str;
		}
	}
}