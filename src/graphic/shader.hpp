#pragma once

#include <GL/glew.h>

#include "../../util/file.h"
#include "../math/mat4.h"

namespace sparky {
	namespace graphic {
		class Shader {
			private:
				GLuint m_Shader;

				const char* m_pathVert;
				const char* m_pathFrag; // pointer doesn't carry over for comma declaration

				GLuint load(const char* srcVert, const char* srcFrag);

				GLint getUniformLocation(GLchar* name);

			public:
				Shader(const char* pathVert, const char* pathFrag);
				~Shader();

				/* void setUniform1f(const GLchar* name, const mat4& matrix); */
				/* void setUniform1i(const GLchar* name, const mat4& matrix); */
				/* void setUniform2f(const GLchar* name, const mat4& matrix); */
				/* void setUniform3f(const GLchar* name, const mat4& matrix); */
				/* void setUniform4f(const GLchar* name, const mat4& matrix); */
				/* void setUniformMat4(const GLchar* name, const mat4& matrix); */

				void enable() const;
				void disable() const;
		};
	}
}
