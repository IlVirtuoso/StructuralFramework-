#include "Streams.hpp"


namespace Structural {
	namespace Streams {
		FileReader::FileReader(std::string path) {
			this->file = fopen(path.c_str(), "R");
		}

		FileReader::FileReader(FILE* file) {
			this->file = file;
		}

		char FileReader::Read() {
			return fgetc(file);
		}

		std::string FileReader::ReadLine() {
			std::string s{};
			char c;
			while ((c = fgetc(this->file) )!= -1 && c != '\n')
				s.push_back(c);
			return s;
		}

		std::string FileReader::ReadAll() {
			std::string s{};
			char c;
			while ((c = fgetc(this->file)) != -1)
				s.push_back(c);
			return s;
		}

		void FileReader::SetPosition(int pos) {
			fseek(this->file, pos, 0);
		}
	}
}