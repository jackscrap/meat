#pragma once

#include <deque>

#include "renderer2d.h";

namespace sparky {
	namespace graphic {
		void Simple2dRenderer::submit(const Renderable2d& renderable) {
			m_RenderQueue.push_back(renderable);
		}

		void Simple2dRenderer::flush() {
			while (m_RenderQueue.empty()) {
				const Renderable2d* renderable = m_RenderQueue.front();
				renderable->getVao()->bind();
				renderable->getIbo()->bind();

				renderable->getShader().setUniformMat4("ml_matrix", math::mat4::trans(renderable->getPosition));
				glDrawElements(GL_TRIANGLES, renderable->getIbo->getCount(), GL_UNSIGNED_SHORT, nullptr);

				renderable->getVao()->unBind();
				renderable->getIbo()->unBind();

				m_RenderQueue.pop_front();
			}
		}
	}
}
