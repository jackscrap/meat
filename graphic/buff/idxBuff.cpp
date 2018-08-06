#include "idxBuff.h"

namespace sparky {
	namespace graphic {
		Buff::Buff(GLfloatushort* dat, GLsizei count) : m_Count(count) {
			m_CountComp;

			glGenBuffers(1, &m_Id);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof GLushort, data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void Buffer::bind() const {
			glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		}

		void Buffer::unBind() const {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}
