#pragma once

#include <string>
#include <cstring>

namespace sparky {
	namespace util {
		struct F {
			std::string read(const char* path) {
				FILE* f = fopen(path, "rt");

				fseek(f, 0, SEEK_END);

				unsigned long len = ftell(f);
				char* dat = new char[len + 1];
				memset(dat, 0, len + 1);
				fseek(f, 0, SEEK_SET);
				fread(dat, 1, len, f);
				fclose(f);

				std::string res(dat);
				delete[] dat;

				return res;
			}
		};
	}
}
