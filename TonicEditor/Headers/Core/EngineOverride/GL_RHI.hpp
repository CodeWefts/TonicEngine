#pragma once
#include "TonicEngine/Core/RHI.hpp"
#include <TonicEngine/Resources/Shader.hpp>


using namespace Resources;


class GL_RHI : public Core::RHI
{
public:
	GL_RHI();

	~GL_RHI();

	void Init(uint32_t width, uint32_t height) override;

	void StartFrame() override;

	// Shader
	void InitShader() override;
	void CheckCompileErrors(unsigned int shader, std::string type) override;
	void InitShaderData() override;
	void DrawTriangle() override;

	void InitFrameBuffer() override;
	void BindFrameBuffer() override;
	void UnbindFrameBuffer() override;
	void RescaleFrameBuffer(s32 width, s32 height) override;
	void ResetViewPort(float width, float height) override;
	unsigned int GetTextureID() override;
	void CleanUp() override;

	void ShaderUse();

private:
	
	Shader* shader_;
	uint32_t width_, height_;
};