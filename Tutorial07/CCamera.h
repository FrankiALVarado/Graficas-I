#pragma once
#include"CBuffer.h"
#include <xnamath.h>

class CCamera
{
	XMMATRIX m_view;
	XMMATRIX m_projection;
	XMVECTOR Eye = XMVectorSet(0.0f, 3.0f, -6.0f, 0.0f);
	XMVECTOR At = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

public:
	CCamera();
	~CCamera();
	void initCamera(XMVECTOR & eye, XMVECTOR & at, XMVECTOR & up);
};

