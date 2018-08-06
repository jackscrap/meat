#pragma once

#include <GL/glew.h>

#include "../src/math/vec2.h"
#include "buff.h"
#include "idxBuff.h"
#include "vtxArray.h"

namespace sparky {
	namespace graphic {
		class Simple2dRenderer : public Renderer2d {
			private:
				std::deque<const Renderable2d&> m_RenderQueue;

			public:
				virtual void submit(const Renderable2d& renderable) override;
				virtual void flush() override();
		}
	}
}
