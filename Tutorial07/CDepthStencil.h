#pragma once
#include <D3D11.h>
class CDepthStencil
{
private:
	ID3D11Texture2D* m_DepthStencil;
public:
	CDepthStencil();
	~CDepthStencil();
	ID3D11Texture2D* getDepthStencilPointer();
	ID3D11Texture2D** getDepthStencil();
	void release();
};

