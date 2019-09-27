#pragma once
#include "CBuffer.h"
#include "Dependencies/ImGui/ImGuiDirectX/imgui.h"
#include "Dependencies/ImGui/ImGuiDirectX/imgui_impl_dx11.h"
#include "Dependencies/ImGui/ImGuiDirectX/imgui_impl_win32.h"

#include "Dependencies/Assimp/include/assimp/scene.h"
#include "Dependencies/Assimp/include/assimp/ai_assert.h"
#include "Dependencies/Assimp/include/assimp/cimport.h"
#include "Dependencies/Assimp/include/assimp/postprocess.h"
#include "Dependencies/Assimp/include/assimp/Importer.hpp"

class CManager
{
private:
	ID3D11Buffer* m_viewBuffer;
	Assimp::Importer m_importer;
	
public:
	CManager();
	~CManager();
	 aiScene * m_model;
	void InitImGui(ID3D11Device *& _device, ID3D11DeviceContext *& _devicecontext, HWND _window);
	void setImGui();
	void loadScene();
	
};

