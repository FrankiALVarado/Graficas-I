#include "Abstractions.h"


CDevice::CDevice()
{
	m_device = nullptr;
}


CDevice::~CDevice()
{
}

ID3D11Device ** CDevice::getDevice()
{
	return &m_device;
}

ID3D11Device * CDevice::getPointerDevice()
{
	return m_device;
}

HRESULT CDevice::createRenderTargetView(ID3D11Resource * pResource, const D3D11_RENDER_TARGET_VIEW_DESC * pDesc, ID3D11RenderTargetView ** ppRTView)
{
	return m_device->CreateRenderTargetView(pResource, pDesc, ppRTView);
}

HRESULT CDevice::createTexture2D(const D3D11_TEXTURE2D_DESC * pDesc, D3D11_SUBRESOURCE_DATA * pInitialData, ID3D11Texture2D ** ppTexture2D)
{
	return m_device->CreateTexture2D(pDesc, pInitialData, ppTexture2D);
}

HRESULT CDevice::createDepthStencilView(ID3D11Resource * pResource, const D3D11_DEPTH_STENCIL_VIEW_DESC * pDesc, ID3D11DepthStencilView ** ppDepthStencilView)
{
	return m_device->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView);
}

HRESULT CDevice::createVertexShader(const void * pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage * pClassLinkage, ID3D11VertexShader ** ppVertexShader)
{
	return m_device->CreateVertexShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppVertexShader);
}

HRESULT CDevice::createInputLayout(const D3D11_INPUT_ELEMENT_DESC * pInputElementDescs, UINT NumElements, const void * pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, ID3D11InputLayout ** ppInputLayout)
{
	return m_device->CreateInputLayout(pInputElementDescs, NumElements, pShaderBytecodeWithInputSignature, BytecodeLength, ppInputLayout);
}

HRESULT CDevice::createPixelShader(const void * pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage * pClassLinkage, ID3D11PixelShader ** ppPixelShader)
{
	return m_device->CreatePixelShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppPixelShader);
}

HRESULT CDevice::createBuffer(const D3D11_BUFFER_DESC * pDesc, const D3D11_SUBRESOURCE_DATA * pInitialData, ID3D11Buffer ** ppBuffer)
{
	return m_device->CreateBuffer(pDesc, pInitialData, ppBuffer);
}

HRESULT CDevice::createSamplerState(const D3D11_SAMPLER_DESC * pSamplerDesc, ID3D11SamplerState ** ppSamplerState)
{
	return m_device->CreateSamplerState(pSamplerDesc, ppSamplerState);
}

HRESULT CDevice::release()
{
	return m_device->Release();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CDeviceContext::CDeviceContext()
{
	m_DeviceContext = nullptr;
}


CDeviceContext::~CDeviceContext()
{
}

ID3D11DeviceContext ** CDeviceContext::getDeviceContext()
{
	return &m_DeviceContext;
}

ID3D11DeviceContext * CDeviceContext::getDevicePointer()
{
	return m_DeviceContext;
}

void CDeviceContext::OMSetRenderTargets(UINT NumViews, ID3D11RenderTargetView * const * ppRenderTargetViews, ID3D11DepthStencilView * pDepthStencilView)
{
	m_DeviceContext->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
}

void CDeviceContext::RSSetViewports(UINT NumViewports, const D3D11_VIEWPORT * pViewports)
{
	m_DeviceContext->RSSetViewports(NumViewports, pViewports);
}

void CDeviceContext::IASetInputLayout(ID3D11InputLayout * pInputLayout)
{
	m_DeviceContext->IASetInputLayout(pInputLayout);
}

void CDeviceContext::IASetVertexBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer * const * ppVertexBuffers, const UINT * pStrides, const UINT * pOffsets)
{
	m_DeviceContext->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}

void CDeviceContext::IAsetIndexBuffers(ID3D11Buffer * pIndexBuffer, DXGI_FORMAT Format, UINT Offset)
{
	m_DeviceContext->IASetIndexBuffer(pIndexBuffer, Format, Offset);
}

void CDeviceContext::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology)
{
	m_DeviceContext->IASetPrimitiveTopology(Topology);
}

void CDeviceContext::updateSubResource(ID3D11Resource * pDstResource, UINT DstSubresource, const D3D11_BOX * pDstBox, const void * pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch)
{
	m_DeviceContext->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
}

void CDeviceContext::clearRenderTargetView(ID3D11RenderTargetView * pRenderTargetView, const FLOAT ColorRGBA[4])
{
	m_DeviceContext->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
}

void CDeviceContext::clearDepthStencilView(ID3D11DepthStencilView * pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil)
{
	m_DeviceContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
}

void CDeviceContext::VSSetShader(ID3D11VertexShader * pVertexShader, ID3D11ClassInstance * const * ppClassInstances, UINT NumClassInstances)
{
	m_DeviceContext->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
}

void CDeviceContext::VSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer * const * ppConstantBuffers)
{
	m_DeviceContext->VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void CDeviceContext::PSSetShader(ID3D11PixelShader * pPixelShader, ID3D11ClassInstance * const * ppClassInstances, UINT NumClassInstances)
{
	m_DeviceContext->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
}

void CDeviceContext::PSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer * const * ppConstantBuffers)
{
	m_DeviceContext->PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void CDeviceContext::PSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView * const * ppShaderResourceViews)
{
	m_DeviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void CDeviceContext::PSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState * const * ppSamplers)
{
	m_DeviceContext->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void CDeviceContext::drawIndexed(UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation)
{
	m_DeviceContext->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
}

void CDeviceContext::clearState()
{
	m_DeviceContext->ClearState();
}

HRESULT CDeviceContext::release()
{
	 return m_DeviceContext->Release();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

CSwapcChain::CSwapcChain()
{
	m_SwapChain = nullptr;
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

HRESULT CSwapcChain::release()
{
	return m_SwapChain->Release();
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

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

HRESULT CDepthStencil::release()
{
	return m_DepthStencil->Release();
}

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


CDepthStencilView::CDepthStencilView()
{
	m_DepthStencilView = nullptr;
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

HRESULT CDepthStencilView::release()
{
	return m_DepthStencilView->Release();
}


////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


CWindow::CWindow()
{
	m_window = nullptr;
	m_instance = nullptr;
}

CWindow::~CWindow()
{
}
