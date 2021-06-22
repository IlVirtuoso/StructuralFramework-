#include "Streams.hpp"

namespace Structural {

	namespace Streams {
		FileReader::FileReader(std::string path) {
			this->file.open(path, std::ios_base::_Openmode::_Openmask);
		}

		FileReader::FileReader(std::ifstream stream) {
			this->file = stream;
		}

		char FileReader::Read() {

		}

		std::string FileReader::ReadLine() {

		}

		void FileReader::SetPosition(int pos) {
			this->file.cur = pos;
		}

		std::string FileReader::ReadAll() {

		}
	}
}