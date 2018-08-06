#include <iostream>
#include <map>

#include "src/graphic/window.hpp"

#include "src/draw.hpp"
#include "src/player.hpp"
#include "src/prop.hpp"

using namespace sparky;
using namespace graphics;

struct point {
	float x,
				y,
				z;
};

struct color {
	float x,
				y,
				z;
};

void drawQuad(float size) {
	glBegin(GL_QUADS);

	glColor3f(0.1, 0.2, 0.3);

	glVertex2f(Window::pos['x'], Window::pos['y']);
	glVertex2f(Window::pos['x'] + size, Window::pos['y']);
	glVertex2f(Window::pos['x'] + size, Window::pos['y'] + size);
	glVertex2f(Window::pos['x'], Window::pos['y'] + size);

	glEnd();
}

void updateMovement() {
	if (Window::pos['y'] > -1) {
		Window::speed['y'] -= .00981;

		if (Window::pos['y'] + Window::speed['y'] > -1) {
			Window::pos['y'] += Window::speed['y'];
		} else {
			Window::pos['y'] = -1;
		}
	} else {
		Window::speed['y'] = 0;
	}
}

int main() {
	std::map<char, int> size = {
		{
			'w', 800
		},
		{
			'h', 600
		}
	};

	Window win("Sparky", size);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	Prop prop;

	prop.size = {
		{
			'w', 1
		},
		{
			'h', 1
		}
	};

	prop.pos = {
		{
			'x', .3
		},
		{
			'y', .6
		}
	};

	while (!win.closed()) {
		Player player;

		win.clear();

		drawQuad(0.1);
		updateMovement();

		prop.draw();


		double x,
					 y;
		win.mousePos(x, y);

		win.update();
	}

	return 0;
}
