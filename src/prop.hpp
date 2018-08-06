#pragma once

#include <iostream>
#include <map>

class Prop {
	public:
		Prop();

		~Prop();

		void draw();

		std::map<char, int> size;
		std::map<char, int> pos;
};
