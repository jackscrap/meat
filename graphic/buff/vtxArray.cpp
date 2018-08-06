#include "vtxArray.h"

namespace sparky {
	namespace graphic {
		VtxArray::VtxArray() {
			glGenVertexarrays(1, &m_id);
		}

		VtxArray::~VtxArray() {
			for (int i = 0; i < m_Buff.size(); i++) {
				delete m_Buff[i];
			}
		}

		void VtxBuffer::addBuff(Buff* buff, GLuint idx) {
			bind();
			buffer->bind();

			glEnableVertexAttribArray(idx);
			glVertexAttribPointer(idx, buff->getCompCount(), GL_FLOAT, GL_FALSE, 0, 0);

			buffer->unBind();
			unBind();
		}

		void VtxArray::bind() const {
			glBindVertexArray(m_Id);
		}

		void VtxArray::unBind() const {
			glBindVertexArray(0);
		}
	}
}
