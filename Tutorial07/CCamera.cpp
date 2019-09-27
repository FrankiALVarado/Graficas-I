#include "CCamera.h"



CCamera::CCamera()
{
}


CCamera::~CCamera()
{
}

void CCamera::initCamera(XMVECTOR & eye, XMVECTOR & at, XMVECTOR & up)
{
	Eye = eye;
	At = at;
	Up = up;
}
