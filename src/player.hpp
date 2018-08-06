#pragma once

#include <map>

class Player {
	public:
		Player();
		~Player();

		void init();

		static std::map<char, float> pos;
};
