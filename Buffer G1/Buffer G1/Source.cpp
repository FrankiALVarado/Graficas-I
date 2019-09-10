#include "CBuffer.h"



int main() {
	unsigned char c = '0';
	float f = 0.0f;  
	
	CBuffer<decltype(c)>Bufferf2;
	Bufferf2.Init(5, 5, R8);
	Bufferf2.setBuffer(3, 0, char(254));
	Bufferf2.setBuffer(1, 1, char(48));
	/*cout << (int)Bufferf2.getBuffer(1, 1) << "\n";*/
	Bufferf2.printBuffer();
	
	CBuffer<decltype(c)>Bufferf;
	Bufferf.Init(6, 3, R8);
	Bufferf.copyBuffer(Bufferf2);
	Bufferf.printBuffer();
	///Bufferf.setBuffer(0, 0, 0.5f);
	//Bufferf.setBuffer(0, 1, 0.5f);
	//Bufferf.printBuffer();
	/*CBuffer<decltype(c)> Bufferuc;
	Bufferuc.Init(2, 2, RGB8);
	Bufferuc.printBuffer();
	Bufferuc.setBuffer(0, 1, char(48));
	Bufferuc.printBuffer();*/
	/*CBuffer<decltype(x)> myBuffer;
	myBuffer.Init(4, 4);
	myBuffer.setBuffer(1, 2, '0');
	myBuffer.setBuffer(0, 0, '8');
	x = myBuffer.getBuffer(0, 0);
	cout << x << "\n";
	x = myBuffer.getBuffer(1, 2);
	cout << x << "\n";
	x = myBuffer.getBuffer(3,3);
	cout << x << "\n";*/
	//myBuffer.printBuffer();

	return 0;
}