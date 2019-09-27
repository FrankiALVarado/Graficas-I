#include "CDevice.h"


CDevice::CDevice()
{
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

void CDevice::release()
{
	m_device->Release();
}
