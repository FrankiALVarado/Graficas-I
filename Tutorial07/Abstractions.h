#pragma once
#include <D3D11.h>

class CDevice
{
public:
	ID3D11Device* m_device;

public:
	CDevice();
	~CDevice();
	ID3D11Device** getDevice();
	ID3D11Device* getPointerDevice();
	HRESULT createRenderTargetView(ID3D11Resource *pResource, const D3D11_RENDER_TARGET_VIEW_DESC *pDesc, ID3D11RenderTargetView **ppRTView);
	HRESULT createTexture2D(const D3D11_TEXTURE2D_DESC *pDesc, D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture2D **ppTexture2D);
	HRESULT createDepthStencilView(ID3D11Resource *pResource, const D3D11_DEPTH_STENCIL_VIEW_DESC *pDesc, ID3D11DepthStencilView **ppDepthStencilView);
	HRESULT createVertexShader(const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11VertexShader **ppVertexShader);
	HRESULT createInputLayout(const D3D11_INPUT_ELEMENT_DESC *pInputElementDescs, UINT NumElements, const void *pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, ID3D11InputLayout **ppInputLayout);
	HRESULT createPixelShader(const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11PixelShader **ppPixelShader);
	HRESULT createBuffer(const D3D11_BUFFER_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Buffer **ppBuffer);
	HRESULT createSamplerState(const D3D11_SAMPLER_DESC *pSamplerDesc, ID3D11SamplerState **ppSamplerState);
	HRESULT release();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CDeviceContext
{
public:
	ID3D11DeviceContext* m_DeviceContext;
public:
	CDeviceContext();
	~CDeviceContext();
	ID3D11DeviceContext** getDeviceContext();
	ID3D11DeviceContext* getDevicePointer();
	void OMSetRenderTargets(UINT NumViews, ID3D11RenderTargetView *const *ppRenderTargetViews, ID3D11DepthStencilView *pDepthStencilView);
	void RSSetViewports(UINT NumViewports, const D3D11_VIEWPORT *pViewports);
	void IASetInputLayout(ID3D11InputLayout *pInputLayout);
	void IASetVertexBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppVertexBuffers, const UINT *pStrides, const UINT *pOffsets);
	void IAsetIndexBuffers(ID3D11Buffer *pIndexBuffer, DXGI_FORMAT Format, UINT Offset);
	void IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);
	void updateSubResource(ID3D11Resource *pDstResource, UINT DstSubresource, const D3D11_BOX *pDstBox, const void *pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch);
	void clearRenderTargetView(ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4]);
	void clearDepthStencilView(ID3D11DepthStencilView *pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil);
	void VSSetShader(ID3D11VertexShader *pVertexShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances);
	void VSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers);
	void PSSetShader(ID3D11PixelShader *pPixelShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances);
	void PSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers);
	void PSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews);
	void PSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers);
	void drawIndexed(UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation);
	void clearState();
	HRESULT release();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	HRESULT release();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

class CDepthStencil
{
private:
	ID3D11Texture2D* m_DepthStencil;
public:
	CDepthStencil();
	~CDepthStencil();
	ID3D11Texture2D* getDepthStencilPointer();
	ID3D11Texture2D** getDepthStencil();
	HRESULT release();
};

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

class CDepthStencilView
{
	ID3D11DepthStencilView* m_DepthStencilView;
public:
	CDepthStencilView();
	~CDepthStencilView();
	ID3D11DepthStencilView* getDepthStencilViewPointer();
	ID3D11DepthStencilView** getDepthStencilView();
	HRESULT release();
};

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

class CWindow
{
private:
	HWND m_window;
	HINSTANCE m_instance;
public:
	CWindow();
	~CWindow();

};
