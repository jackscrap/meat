#pragma once

#include <GL/glew.h>

namespace sparky {
	namespace graphic {
		class IdxBuff; {
			private:
				GLuint = m_Id,
				GLuint = m_Count;

			public:
				IdxBuff(GLushort* dat, GLsizei count);

				void bind() const;
				void unBind() const;

				inline GLuint getCountComp const {
					return m_CountComp;
				}
		}
	}
}
