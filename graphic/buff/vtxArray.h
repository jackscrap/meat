#pragma once

#include <GL/glew.h>

#include <vector>

#include "buff.h"

namespace sparky {
	namespace graphic {
		class VtxArray {
			private:
				GLuint m_Id;
				std::vector<Buffer*> m_Buff;

			public:
				VtxArray();
				~VtxArray();

				void addBuff(Buff* buff, GLuint idx);

				void bind() const;
				void unBind() const;
		}
	}
}
