#pragma once

#include <GL/glew.h>

namespace sparky {
	namespace graphic {
		class Buff {
			private:
				GLuint m_Id,
							 m_CountComp;

			public:
				Buff(GLfloat* dat, GLsizei count, countComp);

				void bind() const;
				void unBind() const;

				inline GLuint getCountComp const {
					return m_CountComp;
				}
		}
	}
}
