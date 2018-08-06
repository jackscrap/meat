#pragma once

#include <GL/glew.h>

#include "shader.h"

#include "renderable2d.h"

namespace sparky {
	namespace graphic {
		class Renderable2d {
			virtual void submit(const Renderable2d* renderable) = 0;
			virtual void flush() = 0;

			/* public: */
			/* 	inline const VtxArray* getVao() const { */
			/* 		return m_VtxArray(); */
			/* 	} */

			/* 	inline const VtxBuff* GetIbo() const { */
			/* 		return m_IdxBuff; */
			/* 	} */


			/* 	inline Shader& getShader() const { */
			/* 		return m_Shader; */
			/* 	} */


			/* 	inline const math::vec3& getPosition() const { */
			/* 		return m_Position; */
			/* 	} */

			/* 	inline const math::vec2& getSize() const { */
			/* 		return m_Size; */
			/* 	} */

			/* 	inline const math::vec4& getColor() const { */
			/* 		return m_Color; */
			/* 	} */


			/* 	math::vec3 m_Pos; */
			/* 	math::vec2 m_Size; */
			/* 	math::vec4 m_Color; */

			/* 	Shader* m_Shader; */
			/* 	VtxArray* m_VtxArray; */
			/* 	Buff* m_VtxBuff; */

			/* 	Renderable2d(maths::vec3 m_Position, math::vec2 size, maths::vec4 color, Shader * shader) : m_Position(position), m_Size(size), m_Color(color), Shader& shader { */
			/* 		m_VtxArray = new VtxArray(); */

			/* 		GLfloat vtx[] = { */
			/* 			0, 0, 0, */
			/* 			0, position.y, 0, */
			/* 			position.x, position.y, 0 */
			/* 			position.x, 0, 0 */
			/* 		}; */

			/* 		GLushort* idc[] = { */
			/* 			0, 1, 2, 3, 3, 0 */
			/* 		}; */

			/* 		GLfloat color[] = { */
			/* 			color.x, color.y, color.z, color.w, */
			/* 			color.x, color.y, color.z, color.w, */
			/* 			color.x, color.y, color.z, color.w, */
			/* 			color.x, color.y, color.z, color.w */
			/* 		}; */

			/* 		m_VtxArray->addBuff(new Buff(vtx, 4 * 3, 3), 0); */
			/* 		m_VtxArray->addBuff(new Buff(color, 4 * 4, 4), 0); */

			/* 		m_IdxBuff = new IdxBuff(idc, 6); */
			/* 	} */

			/* 	virtual ~Renderable2d() { */
			/* 		delete m_VtxArray; */
			/* 		delete m_IdxBuff; */
			/* 	} */
		}
	}
}
