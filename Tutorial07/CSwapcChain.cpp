#include "CSwapcChain.h"



CSwapcChain::CSwapcChain()
{
}


CSwapcChain::~CSwapcChain()
{
}

IDXGISwapChain * CSwapcChain::getSwapChainPointer()
{
	return m_SwapChain;
}

IDXGISwapChain ** CSwapcChain::getSwapChain()
{
	return &m_SwapChain;
}

HRESULT CSwapcChain::getBuffer(UINT Buffer, REFIID riid, void ** ppSurface)
{
	return m_SwapChain->GetBuffer(Buffer, riid, ppSurface);
}

HRESULT CSwapcChain::present(UINT SyncInterval, UINT Flags)
{
	return m_SwapChain->Present(SyncInterval, Flags);
}

void CSwapcChain::release()
{
	m_SwapChain->Release();
}
