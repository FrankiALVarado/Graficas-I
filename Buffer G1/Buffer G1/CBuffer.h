#pragma once
#include <iostream>
#include "Formats.h"
using std::cin;
using std::cout;
/*
	RGBAUN8 = 0
	RGB8 = 1
	RG8 = 2
	R8 = 3
	RGBAF32 = 4
	RGF32 = 5
	RF32 = 6
	NotAFormat = 7

pitch = width * sztype
(y*pitch) + (x * type)
*/

//Width = X
//Height = Y



template<typename T>
class CBuffer
{
private:
    T* m_pointer; 
	int m_pitch;
    int m_width;
    int m_height;
	int m_numChannels;//variable para subir los bytes en la aritmetica de punteros
	int m_bytesz;//variable para utilizar en la función clean que usa un memset con esta variable
	bufferFormat m_bufferFormat;
	char m_answer;
public:
	CBuffer();
	~CBuffer();
	void Init(const int & x, const int & y); //inicializar buffers sin formato
	void Init(const int & x, const int & y, const bufferFormat & format); //inicializar buffers con algun formato
	void setBuffer(const int & x, const int & y, const T& Data);
	T& getBuffer(const int & x, const int & y);
	void printBuffer();
	void printAllElements();
	void cleanBuffer();
	int & getWidth();
	int & getHeight();
	bufferFormat & getFormat();
	void fillBuffer();
	void setWidth(const int & x);
	void setHeight(const int& y);
	void setFormat(const bufferFormat & format);
	void copyBuffer(CBuffer & buffer);
};

template<typename T>
inline CBuffer<T>::CBuffer()
{
	m_pitch = 0;
	m_height = 0;
	m_width = 0;
	m_numChannels = 0;
	m_bytesz = 0;
}

template<typename T>
inline CBuffer<T>::~CBuffer()
{
	free(m_pointer);
}

template<typename T>
inline void CBuffer<T>::Init(const int & x, const int & y) 
{
	
	m_width = x;
	m_height = y;
	m_bytesz = x * y * sizeof(T);
	m_pointer = (T*)malloc(m_bytesz); //cast del void * que regresa el malloc a un puntero del tipo que corresponda
	m_pitch = x * sizeof(T);
	m_bufferFormat = NotAFormat;

	
	cleanBuffer(); //funcion que hace un memset todo a 0.
	
}

template<typename T>
inline void CBuffer<T>::Init(const int & x, const int & y, const bufferFormat & format)
{
	m_width = x;
	m_height = y;
	//m_bytesz = x * y * sizeof(T);
    m_bufferFormat = format;
	switch (format) {
	 case R8:
		 m_numChannels = 1;
		 m_bytesz = x * y;
		 m_pointer = (T*)malloc(m_bytesz);
		 break;
	 case RG8:
		 m_numChannels = 2;
		 m_bytesz = x * y * 2;
		 m_pointer = (T*)malloc(m_bytesz);
		 break;
	 case RGB8:
		 m_numChannels = 3;
		 m_bytesz = x * y * 3;
		 m_pointer = (T*)malloc(m_bytesz);
		 break;
	 case RGBAUN8:
		 m_numChannels = 4;
		 m_bytesz = x * y * 4;
		 m_pointer = (T*)malloc(m_bytesz);
		 break;
	 case RF32:
		 m_numChannels = 1;
		 m_bytesz = x * y * 4;
		 m_pointer = (T*)malloc(m_bytesz);
		 break;
	 case RGF32:
		 m_numChannels = 2;
		 m_bytesz = x * y * 8;
		 m_pointer = (T*)malloc(m_bytesz);
		 break;
	 case RGBF32:
		 m_numChannels = 3;
		 m_bytesz = x * y * 16;
		 m_pointer = (T*)malloc(m_bytesz);
		 break;
	 case RGBAF32:
		 m_numChannels = 4;
		 m_bytesz = x * y * 32;
		 m_pointer = (T*)malloc(m_bytesz);
		 break;
	}
	//m_bytesz = x*y*m_formatBytesz;
	m_pitch = x * m_numChannels; //pitch ya orientado a la aritmetica de punteros
	
	cleanBuffer();
	
}

template<typename T>
inline void CBuffer<T>::setBuffer(const int & x, const int & y, const T& Data)
{
	if (m_bufferFormat == NotAFormat || m_bufferFormat == R8 || m_bufferFormat == RF32) {
		*(m_pointer + (y*m_width) + x) = Data; //calculamos la posición con una coordenada y la igualamos al dato que nos den
	}
	else if (m_bufferFormat == RG8 || m_bufferFormat == RGF32) {
		cout << "canal:" << "\n";
		cout << "1) R" << "\n";
		cout << "2) G" << "\n";
		cin >> m_answer;
		if (m_answer == '1') {
			*(m_pointer + (y*m_pitch) + (x*2) )= Data;
		}
		else if (m_answer == '2') {
			*(m_pointer + (y*m_pitch) + (x*2) + 1) = Data;
		}
	}
	else if (m_bufferFormat == RGB8 || m_bufferFormat == RGBF32) {
		cout << "canal:" << "\n";
		cout << "1) R" << "\n";
		cout << "2) G" << "\n";
		cout << "3) B" << "\n";
		cin >> m_answer;
		if (m_answer == '1') {
			*(m_pointer + (y*m_pitch) + (x * 3)) = Data;
		}
		else if (m_answer == '2') {
			*(m_pointer + (y*m_pitch) + (x * 3) + 1) = Data;
		}
		else if (m_answer == '3') {
			*(m_pointer + (y*m_pitch) + (x * 3) + 2) = Data;
		}
	}
	else if (m_bufferFormat == RGBAF32 || m_bufferFormat == RGBAUN8) {
		cout << "canal:" << "\n";
		cout << "1) R" << "\n";
		cout << "2) G" << "\n";
		cout << "3) B" << "\n";
		cout << "4) A" << "\n";
		cin >> m_answer;
		if (m_answer == '1') {
			*(m_pointer + (y*m_pitch) + (x*m_numChannels)) = Data;
		}
		else if (m_answer == '2') {
			*(m_pointer + (y*m_pitch) + (x*m_numChannels + 1)) = Data;
		}
		else if (m_answer == '3') {
			*(m_pointer + (y*m_pitch) + (x*m_numChannels + 2)) = Data;
		}
		else if (m_answer == '4') {
			*(m_pointer + (y*m_pitch) + (x*m_numChannels + 3)) = Data;
		}
	}
}

template<typename T>
inline T & CBuffer<T>::getBuffer(const int & x, const int & y)
{
	if (m_bufferFormat == NotAFormat) {
		return *(m_pointer + (y*m_width) + x);
	}
	else if (m_bufferFormat == R8 || m_bufferFormat == RF32) {
		return *(m_pointer + (y*m_width) + x);
	}
}

template<typename T>
inline void CBuffer<T>::printBuffer()
{
	if (m_bufferFormat == NotAFormat) {
		for (int j = 0; j < m_height; j++) {
			for (int i = 0 + (j*m_width); i < m_width * (j + 1); i++) {
				cout << *(m_pointer + i) << " | ";
			}
			cout << "\n";
		}
	}
	else if (m_bufferFormat == R8) {
		for (int j = 0; j < m_height; j++) {
			for (int i = 0 + (j*m_width); i < m_width * (j + 1); i++) {
				if (*(m_pointer + i) == ' ') {
					cout << "R8: 0 |";
				}
				else {
					cout << "R8: " << (unsigned int) *(m_pointer + i) << " | ";
				}
			}
			cout << "\n";
		}
	}
	else if (m_bufferFormat == RF32) {
		for (int j = 0; j < m_height; j++) {
			for (int i = 0 + (j*m_width); i < m_width * (j + 1); i++) {
				if (*(m_pointer + i) == 0) {
					cout << "R32: 0 |";
				}
				else {
					cout << "R32: " << *(m_pointer + i) << " | ";
				}
			}
			cout << "\n";
		}
	}
	else if (m_bufferFormat == RG8) {
		for (int j = 0; j < m_height; j++) {
			for (int i = 0 + (j*m_width*2); i < m_width * (j + 1) * 2; i+=2) {
				if (*(m_pointer + i) == ' ') {
					cout << "R8: 0 ,";
				}
				else {
					cout << "R8: " << (unsigned int) *(m_pointer + i) << " , ";
				}
				if (*(m_pointer + i+1) == ' ') {
					cout << "G8: 0 |";
				}
				else {
					cout << "G8: " << (unsigned int) *(m_pointer + i+1) << " | ";
				}
			}
			cout << "\n";
		}
	}
	else if (m_bufferFormat == RGF32) {
		for (int j = 0; j < m_height; j++) {
			for (int i = 0 + (j*m_width * 2); i < m_width * (j + 1) * 2; i += 2) {
				if (*(m_pointer + i) == 0) {
					cout << "R32: 0 ,";
				}
				else {
					cout << "R32: " << *(m_pointer + i) << " , ";
				}
				if (*(m_pointer + i + 1) == 0) {
					cout << "G32: 0 |";
				}
				else {
					cout << "G32: " <<  *(m_pointer + i + 1) << " | ";
				}
			}
			cout << "\n";
		}
	}
	else if (m_bufferFormat == RGB8) {
		for (int j = 0; j < m_height; j++) {
			for (int i = 0 + (j*m_width * 3); i < m_width * (j + 1) * 3; i += 3) {
				if (*(m_pointer + i) == ' ') {
					cout << "R8: 0,";
				}
				else {
					cout << "R8: " << (unsigned int) *(m_pointer + i) << " ,";
				}
				if (*(m_pointer + i + 1) == ' ') {
					cout << "G8: 0 ,";
				}
				else {
					cout << "G8: " << (unsigned int) *(m_pointer + i + 1) << " ,";
				}
				if (*(m_pointer + i + 2) == ' ') {
					cout << "B8: 0 |";
				}
				else {
					cout << "B8: " << (unsigned int) *(m_pointer + i + 2) << " |";
				}
			}
			cout << "\n";
		}
	}
	else if (m_bufferFormat == RGBF32) {
		for (int j = 0; j < m_height; j++) {
			for (int i = 0 + (j*m_width * 3); i < m_width * (j + 1) * 3; i += 3) {
				if (*(m_pointer + i) == 0) {
					cout << "R32: 0,";
				}
				else {
					cout << "R32: " << *(m_pointer + i) << " ,";
				}
				if (*(m_pointer + i + 1) == 0) {
					cout << "G32: 0 ,";
				}
				else {
					cout << "G32: " << *(m_pointer + i + 1) << " ,";
				}
				if (*(m_pointer + i + 2) == 0) {
					cout << "B32: 0 |";
				}
				else {
					cout << "B32: " <<  *(m_pointer + i + 2) << " |";
				}
			}
			cout << "\n";
		}
	}
	else if (m_bufferFormat == RGBAUN8) {
		for (int j = 0; j < m_height; j++) {
			for (int i = 0 + (j*m_width * 4); i < m_width * (j + 1) * 4; i += 4) {
			if (*(m_pointer + i) == ' ') {
				cout << "R8: 0,";
			}
			else {
				cout << "R8: " << (unsigned int) *(m_pointer + i) << " ,";
			}
			if (*(m_pointer + i + 1) == ' ') {
				cout << "G8: 0 ,";
			}
			else {
				cout << "G8: " << (unsigned int) *(m_pointer + i + 1) << " ,";
			}
			if (*(m_pointer + i + 2) == ' ') {
				cout << "B8: 0 ,";
			}
			else {
				cout << "B8: " << (unsigned int) *(m_pointer + i + 2) << " ,";
			}
			if (*(m_pointer + i + 3) == ' ') {
				cout << "A8: 0 |";
			}
			else {
				cout << "A8: " << (unsigned int) *(m_pointer + i + 3) << " |";
			}
		}
		cout << "\n";
	  }

    }
	else if (m_bufferFormat == RGBAF32) {
		for (int j = 0; j < m_height; j++) {
			for (int i = 0 + (j*m_width * 4); i < m_width * (j + 1) * 4; i += 4) {
			if (*(m_pointer + i) == 0) {
				cout << "R32: 0,";
			}
			else {
				cout << "R32: " << *(m_pointer + i) << " ,";
			}
			if (*(m_pointer + i + 1) == 0) {
				cout << "G32: 0 ,";
			}
			else {
				cout << "G32: " << *(m_pointer + i + 1) << " ,";
			}
			if (*(m_pointer + i + 2) == 0) {
				cout << "B32: 0 ,";
			}
			else {
				cout << "B32: " << *(m_pointer + i + 2) << " ,";
			}
			if (*(m_pointer + i + 3) == 0) {
				cout << "A32: 0 |";
			}
			else {
				cout << "A32: " << *(m_pointer + i + 3) << " |";
			}
		}
		cout << "\n";
		}
	}
	cout << "\n";
}

template<typename T>
inline void CBuffer<T>::printAllElements()
{
	for (int i = 0; i < (m_width * m_height) - 1; i++) {
		cout << *(m_pointer + i) << "\n";
	}
}

template<typename T>
inline void CBuffer<T>::cleanBuffer()
{
	if (m_bufferFormat != NotAFormat) {
		if (sizeof(T) == sizeof(char)) {
			memset(m_pointer, ' ', m_bytesz);
		}
		else {
			memset(m_pointer, 0, m_bytesz);
		}
	}
	else {
		if (sizeof(T) == sizeof(char)) {
			memset(m_pointer, '0', m_bytesz);
		}
		else {
			memset(m_pointer, 0, m_bytesz);
		}
	}
	
}

template<typename T>
inline int & CBuffer<T>::getWidth()
{
	return m_width;
}

template<typename T>
inline int & CBuffer<T>::getHeight()
{
	return m_height;
}

template<typename T>
inline bufferFormat & CBuffer<T>::getFormat()
{
	return m_bufferFormat;
}

template<typename T>
inline void CBuffer<T>::fillBuffer()
{
	for (int i = 0; i < m_width * m_height * m_numChannels; i++) {
		m_pointer[i] = 0;
	}
}

template<typename T>
inline void CBuffer<T>::setWidth(const int & x)
{
	m_width = x;
}

template<typename T>
inline void CBuffer<T>::setHeight(const int & y)
{
	m_height = y;
}

template<typename T>
inline void CBuffer<T>::setFormat(const bufferFormat & format)
{
	m_bufferFormat = format;
}

template<typename T>
inline void CBuffer<T>::copyBuffer(CBuffer<T> & buffer)
{
	if (m_bufferFormat == buffer.getFormat()) {
		if (m_height == buffer.getHeight() && m_width == buffer.getWidth()) {
			*this = buffer;
		}
		else if (buffer.m_numChannels == 1) {
			float n = 1 / m_width;
			int x;
			int y;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					//cout << (int) buffer.getBuffer(x, y) << "\n";
					if (buffer.getBuffer(n*i*buffer.getWidth(), n*j*buffer.getHeight()) != ' ') {
						cout << (int)buffer.getBuffer(x, y) << "\n";
						*(m_pointer + (i + (j * m_width))) = buffer.getBuffer(n*i*buffer.getWidth(), n*j*buffer.getHeight());
					}
				}
			}
		}
	}
}


