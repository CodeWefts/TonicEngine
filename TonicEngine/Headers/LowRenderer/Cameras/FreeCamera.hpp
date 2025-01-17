#pragma once
#include <DLL_API.hpp>

#include "Maths/Maths.hpp"
#include "Camera.hpp"

#include <Core/Utils/Type.hpp>
#include <Core/Utils/f32_2.hpp>

namespace Core::Renderer { class OpenGLWrapper; }

namespace LowRenderer::Cameras
{
	struct TONIC_ENGINE_API CameraInput
	{
		float deltaX;
		float deltaY;
		float zoom;
		bool bMoveForward;
		bool bMoveBackward;
		bool bMoveUp;
		bool bMoveDown;
		bool bMoveLeft;
		bool bMoveRight;
		// ... and more if needed
		bool NoInputs() const;
	};

	struct TONIC_ENGINE_API Input
	{
		//Only for scene vizualizer Camera
		CameraInput cameraInput{};
		struct Mouse
		{
			f32_2 pos;
		};
		Mouse mouse;
	};

	class FreeCamera : public Camera
	{
		/**********************************************
				VARIABLES BLOC
		**********************************************/
	public:
		Maths::Vec3 eye, center, up;
		Maths::Vec3 forward;

		float camSpeed = 8.f;
		float camRotationSpeed = 0.1f;
		float zoomSpeed = 0.1f;

		/*********************************************
				FUNCTIONS BLOC
		*********************************************/

		TONIC_ENGINE_API FreeCamera(unsigned int _width, unsigned int _height);

		void TONIC_ENGINE_API SetView();
		void TONIC_ENGINE_API Update();

		void TONIC_ENGINE_API LookAt(float _x, float _y, float _z);
		void TONIC_ENGINE_API LookAt(const Maths::Vec3& _target);

		void TONIC_ENGINE_API Move(const Maths::Vec3& _velocity);
		void TONIC_ENGINE_API Turn(float _angle, Maths::Vec3 _axis);

		void TONIC_ENGINE_API ProcessInput(float _deltaTime, const CameraInput& _inputs);
		void TONIC_ENGINE_API Zoom(float _yoffset);
		void TONIC_ENGINE_API Teleport(Maths::Vec3 _position);
		void TONIC_ENGINE_API Teleport(Maths::Vec3 _position, Maths::Vec3 _target);
	};
}