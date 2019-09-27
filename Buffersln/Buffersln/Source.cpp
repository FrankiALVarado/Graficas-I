#include "CBuffer.h"

int main() {
//	unsigned char x = 204;
//	float  y = 0.8f;
//	CBuffer myBuffer;
//	bufferFormat format = RGF32;
//	bufferFormat format2 = R8;
//	myBuffer.initBuffer(5, 5, format);
//	myBuffer.setData(2, 1, y);
//	myBuffer.setData(1, 1, y);
//	myBuffer.setData(0, 0, y);
//	myBuffer.setData(0, 1, y);
////	myBuffer.printBuffer();
//
//	CBuffer buffer2;
//	buffer2.initBuffer(3, 3, format2);
//	buffer2.copyBuffer(myBuffer);
//	//buffer2.printBuffer();
//

	CBuffer Line;
	Line.initBuffer(10, 10, NotAFormat);
	Line.drawAlgebraicLine(1, 2, 7, 5);
	Line.drawBresenhamLine(1, 2, 7, 5);
	Line.drawAlgegraicCircle(3);
	return 0;
}