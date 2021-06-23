#include "FileSystem.hpp"
namespace Structural {
	namespace FileSystem {
		File::File(std::string path, OpenModes openmode) {
			std::string open{ openmode };
			this->file = fopen(path.c_str(),open.c_str());
			stat(this->path.c_str(), this->st);
		}

	

		bool File::isDir() {
			return (st->st_mode & S_IFMT ) == S_IFDIR;
		}

		bool File::isFile() {
			return (st->st_mode & S_IFMT) == S_IFREG;
		}

		bool File::isSocket() {
			return (st->st_mode & S_IFMT) == S_IFMT;
		}

		bool File::isPipe() {
			return (st->st_mode & S_IFMT) == S_IFCHR;
		}


	}
}