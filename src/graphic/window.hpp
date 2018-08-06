#pragma once

#include <iostream>
#include <map>

#include <GL/glew.h>
#include "../../dep/glfw/glfw3.h"

#define MAX_KEY 1024
#define MAX_BTN 32

namespace sparky {
	namespace graphics {
		class Window {
			private:
				const char* m_Title;
				std::map<char, int> m_Size;

				GLFWwindow *m_Window;

				bool m_Key[MAX_KEY],
						 m_Btn[MAX_BTN];

				bool m_Closed;

				bool init();

				friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
				friend void btn_callback(GLFWwindow* window, int key, int btn, int action);

				friend void cursor_pos_callback(GLFWwindow* window, int key, int btn, int action, int mods);

			public:
				Window(const char* title, std::map<char, int> size);

				~Window();

				std::map<int, char> m_Curs;

				static std::map<char, float> pos,
																		 speed;

				void clear() const;
				void update();
				bool closed() const;

				bool pressedKey(unsigned int code);
				bool pressedBtn(unsigned int btn);
				void mousePos(unsigned int x, unsigned int y);
		};
	}
}
