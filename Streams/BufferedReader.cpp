#include "Streams.hpp"


namespace Structural {

	namespace Streams {
		BufferedFileReader::BufferedFileReader(std::string path) {
			this->file = fopen(path.c_str(),"r");
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
				c = 0;
				for (register int i = 0; i < 128 && c != -1; i++) {
					c = fgetc(this->file);
					this->buffer[i] = c;
				}
			}
			if (!endOfFile) {
				c = this->buffer[this->pointer];
				pointer++;
				if (c == -1)
					endOfFile = true;
				if (pointer == 128) {
					free(this->buffer);
					this->buffer = NULL;
					pointer = 0;
				}
			}
			return c;
		}

		std::string BufferedFileReader::ReadLine() {
			std::string str{};
			char c;
			while ((c = Read()) != -1 && c != '\n')
				str.push_back(c);
			return str;
		}

		void BufferedFileReader::SetPosition(const int pos) {
			if (pos >= this->Size()) throw new std::exception("position over boundary limits");
			const fpos_t arg = pos;
			fsetpos(this->file, &arg);
		}

		std::string BufferedFileReader::ReadAll() {
			std::string str{};
			char c;
			while ((c = Read()) != -1)
				str.push_back(c);
			return str;
		}

		int BufferedFileReader::Size() {
			fpos_t currentPos = 0;
			fgetpos(this->file, &currentPos);
			char c;
			while ((c = Read()) != -1);
			fpos_t length = 0;
			fgetpos(this->file, &length);
			fsetpos(this->file, &currentPos);
			return length;
		}
	}



}