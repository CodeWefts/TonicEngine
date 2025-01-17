#pragma once
#include "ILight.hpp"

namespace ECS::Systems { class DirectionalLightSystem; }
namespace Core::Renderer { class OpenGLWrapper; }

namespace LowRenderer::Lights
{
	class DirectionalLight : public ILight
	{
		/*********************************************
				FUNCTIONS BLOC
		*********************************************/
	public:
		TONIC_ENGINE_API DirectionalLight() = default;
		TONIC_ENGINE_API DirectionalLight(const DirectionalLight&) = default;
		TONIC_ENGINE_API ~DirectionalLight() = default;

		friend class ECS::Systems::DirectionalLightSystem;
		friend class Core::Renderer::OpenGLWrapper;
	};
}