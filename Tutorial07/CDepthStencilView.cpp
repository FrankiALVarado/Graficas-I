#include "CDepthStencilView.h"



CDepthStencilView::CDepthStencilView()
{
}


CDepthStencilView::~CDepthStencilView()
{
}

ID3D11DepthStencilView * CDepthStencilView::getDepthStencilViewPointer()
{
	return m_DepthStencilView;
}

ID3D11DepthStencilView ** CDepthStencilView::getDepthStencilView()
{
	return &m_DepthStencilView;
}

void CDepthStencilView::release()
{
	m_DepthStencilView->Release();
}
