#pragma once
#include <D3D11.h>
class CSwapcChain
{
private:
	IDXGISwapChain* m_SwapChain;
public:
	CSwapcChain();
	~CSwapcChain();

	IDXGISwapChain* getSwapChainPointer();
	IDXGISwapChain** getSwapChain();
	HRESULT getBuffer(UINT Buffer, __in  REFIID riid, void **ppSurface);
	HRESULT present(UINT SyncInterval, UINT Flags);
	void release();
};

