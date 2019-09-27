#pragma once
#include <D3D11.h>
class CDepthStencilView
{
	ID3D11DepthStencilView* m_DepthStencilView;
public:
	CDepthStencilView();
	~CDepthStencilView();
	ID3D11DepthStencilView* getDepthStencilViewPointer();
	ID3D11DepthStencilView** getDepthStencilView();
	void release();
};

