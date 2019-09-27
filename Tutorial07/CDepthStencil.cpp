#include "CDepthStencil.h"



CDepthStencil::CDepthStencil()
{
	m_DepthStencil = nullptr;
}


CDepthStencil::~CDepthStencil()
{
}

ID3D11Texture2D * CDepthStencil::getDepthStencilPointer()
{
	return m_DepthStencil;
}

ID3D11Texture2D ** CDepthStencil::getDepthStencil()
{
	return &m_DepthStencil;
}

void CDepthStencil::release()
{
	m_DepthStencil->Release();
}
