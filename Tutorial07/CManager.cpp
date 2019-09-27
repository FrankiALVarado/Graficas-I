#include "CManager.h"



CManager::CManager()
{
	m_viewBuffer = nullptr;
}


CManager::~CManager()
{
}

void CManager::InitImGui(ID3D11Device *& _device, ID3D11DeviceContext *& _devicecontext, HWND _window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplWin32_Init(_window);
	ImGui_ImplDX11_Init(_device, _devicecontext);
	ImGui::StyleColorsDark();
}

void CManager::setImGui()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::Begin("FrameRate");
	ImGui::SetWindowSize(ImVec2(25, 25), ImGuiSetCond_FirstUseEver);
	ImGui::SetWindowPos(ImVec2(2, 2), ImGuiSetCond_FirstUseEver);
	ImGui::Text("%.0f ms/frame (%.1f FPS)", 1000.0 / double(ImGui::GetIO().Framerate), double(ImGui::GetIO().Framerate));
	ImGui::End();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void CManager::loadScene()
{
	m_importer.ReadFile("C:\\Users\\frank\\OneDrive\\Escritorio\\DirectXSamples\\Tutorial07\\Scene", 0);
	m_model = m_importer.GetOrphanedScene();
	if (!m_model) {
		aiGetErrorString();
	}
}
