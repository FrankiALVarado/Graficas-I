#pragma once
#include "Formats.h"
#include <Windows.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class CBuffer
{
private:
	void* m_Buffer;
	int m_width;
    int m_height;
	int m_pitch;
	int m_bytesz;
	int m_numChannels;
	int m_currentIndex;
	bufferFormat m_format;
public:
	CBuffer();
	~CBuffer();
	
	void* getPointer();
	int & getWidth();
	int & getHeight();
	int & getPitch();
	int & getNumChannels();
	bufferFormat & getFormat();

	void initBuffer(const int & _width, const int & _height,  const bufferFormat & _format);
	void clearBuffer();
	void printBuffer();

	void setData(const int & x, const int & y, unsigned char & data);
	void setData(const int & x, const int & y, float & data);

	bool isDatainCoord(const int & x, const int & y);

	void drawAlgebraicLine(const int & x1,  const int & y1, const int & x2, const int & y2);
	void drawBresenhamLine(const int & x1, const int & y1, const int & x2, const int & y2);
	void drawAlgegraicCircle(const int & radius);

	void copyBuffer(CBuffer & buffer);
};

