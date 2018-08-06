#include <GL/glew.h>
#include <iostream>

#include "prop.hpp"

Prop::Prop() {
}

Prop::~Prop() {
}

void Prop::draw() {
	glBegin(GL_QUADS);

	glColor3f(0.6, 0.0, 0.0);

	glVertex2f(this->pos['x'], this->pos['y']);
	glVertex2f(this->pos['x'] + this->size['w'], this->pos['y']);
	glVertex2f(this->pos['x'] + this->size['w'], this->pos['y'] + this->size['h']);
	glVertex2f(this->pos['x'], this->pos['y'] + this->size['h']);

	glEnd();
}
