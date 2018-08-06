#include "buff.h"

namespace sparky {
	namespace graphic {
		Buff::Buff(GLfloat* dat, GLsizei count, GLuint countComp) : m_CountComp(countComp) {
			m_CountComp;

			glGenBuffers(1, &m_Id);
			glBindBuffer(GL_ARRAY_BUFFER, m_Id);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof GLfloat, data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void Buffer::bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		}

		void Buffer::unBind() const {
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}
