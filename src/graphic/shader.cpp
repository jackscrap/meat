#include <GL/glew.h>
#include <iostream>
#include <string>
#include <vector>

#include "../math/vec4.h"
#include "shader.h"
#include "../../util/file.h"

namespace sparky {
	namespace graphic {
		Shader::Shader(const char* pathVert, const char* pathFrag) {
			m_Shader = load();
		}

		Shader::~Shader() {
			glDeleteProgram(m_Shader);
		}

		GLuint Shader::load() {
			GLuint prog = glCreateProgram();
			GLuint vert = glCreateShader(GL_VERTEX_SHADER);
			GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);

			std::string srcVertStr = sparky::util::F::read(m_pathVert);
			std::string srcFragStr = sparky::util::F::read(m_pathFrag);

			const char* srcVert = srcVertStr.c_str();
			const char* srcFrag = srcFragStr.c_str();


			glShaderSource(vert, 1, &srcVert, NULL);
			glCompileShader(vert);

			GLint resVert;
			glGetShaderiv(vert, GL_COMPILE_STATUS, &resVert);

			/* if (resVert == GL_FALSE) { */
			/* 	GLint len; */
			/* 	glGetShaderiv(vert, GL_LOG_INFO_LENGTH, &len); */
			/* 	std::vector<char> err(len); */
			/* 	glGetShaderInfoLog(vert, len, &len, &err[0]); */

			/* 	std::cout << &err[0] << std::endl; */

			/* 	glDeleteShader(vert); */

			/* 	return 0; */
			/* } */


			glShaderSource(frag, 1, &srcFrag, NULL);
			glCompileShader(frag);

			GLint resFrag;
			glGetShaderiv(frag, GL_COMPILE_STATUS, &resFrag);

			/* if (resFrag == GL_FALSE) { */
			/* 	GLint len; */
			/* 	glGetShaderiv(frag, GL_LOG_INFO_LENGTH, &len); */
			/* 	std::vector<char> err(len); */
			/* 	glGetShaderInfoLog(frag, len, &len, &err[0]); */

			/* 	std::cout << &err[0] << std::endl; */

			/* 	glDeleteShader(frag); */

			/* 	return 0; */
			/* } */


			glAttachShader(prog, vert);
			glAttachShader(prog, frag);

			glLinkProgram(prog);
			glValidateProgram(prog);

			glDeleteShader(vert);
			glDeleteShader(frag);

			return prog;
		}


		/* GLint Shader::getUniformLocation(GLchar* name) { */
		/* 	return glGetUniformLocation(m_Shader, name); */
		/* } */

		/* void Shader::setUniform1f(const GLchar* name, float val) { */
		/* 	glUniform1f(getUniformLocation(name), val); */
		/* } */

		/* void Shader::setUniform1i(const GLchar* name, int val) { */
		/* 	glUniform1i(getUniformLocation(name), val); */
		/* } */

		/* void Shader::setUniform2f(const GLchar* name, const vec2& vec) { */
		/* 	glUniform2f(getUniformLocation(name), vec.x, vec.y); */
		/* } */

		/* void Shader::setUniform3f(const GLchar* name, const vec3& vec) { */
		/* 	glUniform3f(getUniformLocation(name), vec.x, vec.y, vec.z); */
		/* } */

		/* void Shader::setUniform4f(const GLchar* name, const vec4& vec) { */
		/* 	glUniform4f(getUniformLocation(name), vec.x, vec.y, vec.z, vec.w); */
		/* } */

		/* void Shader::setUniformMat4(const GLchar* name, const mat4& matrix) { */
		/* 	glUniformMatrix4f(getUniformLocation(name), 1, GL_FALSE, matrix.el); */
		/* } */


		void Shader::enable() const {
			glUseProgram(m_Shader);
		}

		void Shader::disable() const {
			glUseProgram(m_Shader);
		}
	}
}
