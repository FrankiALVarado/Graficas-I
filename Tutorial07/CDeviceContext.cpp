#include "CDeviceContext.h"




CDeviceContext::CDeviceContext()
{
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

void CDeviceContext::release()
{
	m_DeviceContext->Release();
}
