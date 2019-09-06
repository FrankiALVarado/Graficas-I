#pragma once
#include <iostream>
using std::cin;
using std::cout;
/*
Nsig Nvidia
RenderMonkey
Directx SDK 11 jun 2011 tutorial 7

Init(W,H,Type)
set (X,Y, Data)
type Get (X,Y)
Print Buffer()
aprende malloc
lee documentación de assimp
OPC puntero al inicio del buffer

pitch = width * sztype
(y*pitch) + (x * type)
*/

//Width = X
//Height = Y
template<typename T>

class CBuffer
{
private:
    T* m_pointer; //
	int m_pitch;
    int m_width;
    int m_height;
	int m_bytesz; //tamaño en bytes total del puntero
public:
	CBuffer();
	~CBuffer();
	void Init(int x, int y);
	void setBuffer(int x, int y, const T& Data);
	T& getBuffer(const int & x, const int & y);
	void printBuffer();
	void cleanBuffer();
	
};

template<typename T>
inline CBuffer<T>::CBuffer()
{
	m_pitch = 0;
	m_height = 0;
	m_width = 0;
	m_bytesz = 0;
}

template<typename T>
inline CBuffer<T>::~CBuffer()
{
	free(m_pointer);
}

template<typename T>
inline void CBuffer<T>::Init(int x, int y) 
{
	
	m_width = x;
	m_height = y;
	m_bytesz = x * y * sizeof(T);
	m_pointer = (T*)malloc(m_bytesz); //cast del void * que regresa el malloc a un puntero del tipo que corresponda
	m_pitch = x * sizeof(T);


	cleanBuffer(); //funcion que hace un memset todo a 0.
	
}

template<typename T>
inline void CBuffer<T>::setBuffer(int x, int y, const T& Data) 
{
	*(m_pointer + (y*m_width) + x) = Data; //calculamos la posición con una coordenada y la igualamos al dato que nos den
}

template<typename T>
inline T & CBuffer<T>::getBuffer(const int & x, const int & y)
{
	return *(m_pointer + (y*m_width) + x);
}

template<typename T>
inline void CBuffer<T>::printBuffer()
{
	for (int j = 0; j < m_height; j++) {
		for (int i = 0 + (j*m_width); i < m_width * (j+1); i++) {
			cout << *(m_pointer+i) << "     ";
		}
		cout << "\n";
	}
}

template<typename T>
inline void CBuffer<T>::cleanBuffer()
{
	memset(m_pointer, 0, m_bytesz);
}


