#include "CBuffer.h"


int main() {
	int x = 0;
	CBuffer<int> myBuffer;
	myBuffer.Init(4, 4);
	myBuffer.setBuffer(1, 2, 50);
	myBuffer.setBuffer(0, 0, 8);
	x = myBuffer.getBuffer(0, 0);
	cout << x << "\n";
	x = myBuffer.getBuffer(1, 2);
	cout << x << "\n";
	x = myBuffer.getBuffer(1, 3);
	cout << x << "\n";
	myBuffer.printBuffer();

	return 0;
}