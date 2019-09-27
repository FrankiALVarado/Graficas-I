#include "CBuffer.h"



CBuffer::CBuffer()
{
	m_width = 0;
	m_height = 0;
	m_pitch = 0;
	m_bytesz = 0;
	m_format = NotAFormat;
	m_currentIndex = 0;
}


CBuffer::~CBuffer()
{
	clearBuffer();
	free(m_Buffer);
}

void * CBuffer::getPointer()
{
	return m_Buffer;
}

int & CBuffer::getWidth()
{
	return m_width;
}

int & CBuffer::getHeight()
{
	return m_height;
}

int & CBuffer::getPitch()
{
	return m_pitch;
}

int & CBuffer::getNumChannels()
{
	return m_numChannels;
}

bufferFormat & CBuffer::getFormat()
{
	return m_format;
}

void CBuffer::initBuffer(const int & _width, const int & _height,  const bufferFormat & _format)
{

	m_width = _width;
	m_height = _height;
	m_format = _format;

	if (_format <= RGBAUN8) { //casos para los formatos de 8 bits
		switch (_format)
		{
		case R8:
			m_numChannels = 1;
			m_bytesz = m_width * m_height;
			m_Buffer = (unsigned char*)malloc(m_bytesz);
			break;
		case RG8:
			m_numChannels = 2;
			m_bytesz = m_width * m_height * m_numChannels;
			m_Buffer = (unsigned char*)malloc(m_bytesz);
			break;
		case RGB8:
			m_numChannels = 3;
			m_bytesz = m_width * m_height * m_numChannels;
			m_Buffer = (unsigned char*)malloc(m_bytesz);
			break;
		case RGBAUN8:
			m_numChannels = 4;
			m_bytesz = m_width * m_height * m_numChannels;
			m_Buffer = (unsigned char*)malloc(m_bytesz);
			break;
		default:
			break;
		}
	
	}
	else if (_format <= RGBAF32) { //casos para los formatos de 32 bits
		switch (_format)
		{
		case RF32 :
			m_numChannels = 1;
			m_bytesz = m_width * m_height * 4;
			m_Buffer = (float*)malloc(m_bytesz);
			break;
		case RGF32 :
			m_numChannels = 2;
			m_bytesz = m_width * m_height * m_numChannels * 4;
			m_Buffer = (float*)malloc(m_bytesz);
			break;
		case RGBF32:
			m_numChannels = 3;
			m_bytesz = m_width * m_height * m_numChannels * 4;
			m_Buffer = (float*)malloc(m_bytesz);
			break;
		case RGBAF32:
			m_numChannels = 4;
			m_bytesz = m_width * m_height * m_numChannels * 4;
			m_Buffer = (float*)malloc(m_bytesz);
			break;
		default:
			break;
		}
	}
	else { //caso NotaFormat
		m_bytesz = m_width * m_height;
		m_numChannels = 1;
		m_Buffer = (unsigned char*)malloc(m_bytesz);
	}

	m_pitch = _width * m_numChannels; //pitch orientado a la aritmetica del puntero 
	clearBuffer(); //inicializar en 0 los valores
}

void CBuffer::clearBuffer()
{
	if (m_format <= RGBAUN8 || m_format == NotAFormat ) {
		memset(m_Buffer, '\0', m_bytesz);
	}
	else {
		memset(m_Buffer, 0, m_bytesz);
	}
}


void CBuffer::printBuffer()
{
	if (m_format == NotAFormat)
	{
		for (int j = 0; j < m_height; j++) {
			for (int i = 0; i < m_width; i++) {
				cout << * ((unsigned char*)m_Buffer + m_currentIndex) << " | ";
				m_currentIndex++;
			}
			cout << endl;
		}
		m_currentIndex = 0;
	}
	else  if(m_format <= RGBAUN8){
		if (m_numChannels == 1) {
			for (int j = 0; j < m_height; j++) {
				for (int i = 0; i < m_width; i++) {
					cout << "R: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << " | ";
					m_currentIndex++;
				}
				cout << endl;
			}
			m_currentIndex = 0;
		}
		else if (m_numChannels == 2) {
			for (int j = 0; j < m_height; j++) {
				for (int i = 0; i < m_width; i++) {
					cout << "R: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "G: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << " | ";
					m_currentIndex++;
				}
				cout << endl;
			}
			m_currentIndex = 0;
		}
		else if (m_numChannels == 3) {
			for (int j = 0; j < m_height; j++) {
				for (int i = 0; i < m_width; i++) {
					cout << "R: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "G: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "B: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << " | ";
					m_currentIndex++;
				}
				cout << endl;
			}
			m_currentIndex = 0;
		}
		else if (m_numChannels == 4) {
			for (int j = 0; j < m_height; j++) {
				for (int i = 0; i < m_width; i++) {
					cout << "R: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "G: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "B: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "A: " << (int)*((unsigned char*)m_Buffer + m_currentIndex) << " | ";
					m_currentIndex++;
				}
				cout << endl;
			}
			m_currentIndex = 0;
		}
	}
	else if (m_format <= RGBAF32) {
		if (m_numChannels == 1) {
			for (int j = 0; j < m_height; j++) {
				for (int i = 0; i < m_width; i++) {
					cout << "R: " << *((float*)m_Buffer + m_currentIndex) << " | ";
					m_currentIndex++;
				}
				cout << endl;
			}
			m_currentIndex = 0;
		}
		else if (m_numChannels == 2) {
			for (int j = 0; j < m_height; j++) {
				for (int i = 0; i < m_width; i++) {
					cout << "R: " << *((float*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "G: " << *((float*)m_Buffer + m_currentIndex) << " | ";
					m_currentIndex++;
				}
				cout << endl;
			}
			m_currentIndex = 0;
		}
		else if (m_numChannels == 3) {
			for (int j = 0; j < m_height; j++) {
				for (int i = 0; i < m_width; i++) {
					cout << "R: " << *((float*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "G: " << *((float*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "B: " << *((float*)m_Buffer + m_currentIndex) << " | ";
					m_currentIndex++;
				}
				cout << endl;
			}
			m_currentIndex = 0;
		}
		else if (m_numChannels == 4) {
			for (int j = 0; j < m_height; j++) {
				for (int i = 0; i < m_width; i++) {
					cout << "R: " << *((float*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "G: " << *((float*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "B: " << *((float*)m_Buffer + m_currentIndex) << ", ";
					m_currentIndex++;
					cout << "A: " << *((float*)m_Buffer + m_currentIndex) << " | ";
					m_currentIndex++;
				}
				cout << endl;
			}
			m_currentIndex = 0;
		}
	}
}

void CBuffer::setData(const int & x, const int & y, unsigned char& data) //funcion para setear informacion a un formato de 8 bits, si hay más de un canal se le ayuda al usuario a setearlo
{
	if (x >= m_width || y >= m_height) { //en caso de desbordamiento del tamaño del buffer
		cout << "oversized dimension from buffer" << endl;
		return;
	}


	if (m_format == NotAFormat) {
		*((unsigned char*)m_Buffer + (y * m_pitch) + x) = data;
		return;
	}

	if (m_format <= RGBAUN8) {
		char answer;
		if (m_numChannels == 1) {
			*((unsigned char*)m_Buffer + (y * m_pitch) + x) = data;
			return;
		}
		else if (m_numChannels == 2) {
			cout << "1)R" << endl;
			cout << "2)G" << endl;
			cin >> answer;

			if (answer == '1') {
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) = data;
			}
			else {
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) = data;

			}
			return;
		}
		else if (m_numChannels == 3) {
			cout << "1)R" << endl;
			cout << "2)G" << endl;
			cout << "3)B" << endl;
			cin >> answer;
			if (answer == '1') {
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) = data;
			}
			else if (answer == '2') {
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels)+ 1) = data;
			}
			else {
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 2) = data;
			}
			return;
		}
		else if (m_numChannels == 4) {
			cout << "1)R" << endl;
			cout << "2)G" << endl;
			cout << "3)B" << endl;
			cout << "4)A" << endl;
			cin >> answer;
			if (answer == '1') {
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) = data;
			}
			else if (answer == '2') {
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) = data;
			}
			else if(answer == '3') {
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 2) = data;
			}
			else {
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 3) = data;
			}
			return;
		}
	}
	else {
		cout << "buffer is not using this type of data" << endl;
		return;
	}
}

void CBuffer::setData(const int & x, const int & y, float & data)//funcion para setear informacion a un formato de 32 bits, si hay más de un canal se le ayuda al usuario a setearlo
{
	if (x >= m_width || y >= m_height) { //desbordamiento del buffer
		cout << "oversized dimension from buffer" << endl;
		return;
	}
//normalizacion del valor para el caso de 32 bits
///////////////////////
	if (data < 0) {
		data = 0;
	}
	if (data > 1) {
		data = 1;
	}
//////////////////////
	if (m_format <= RGBAUN8 || m_format == NotAFormat) {
		cout << "buffer is not using this type of data" << endl;
		return;
	}
	else {
		char answer;
		if (m_numChannels == 1) {
			*((float*)m_Buffer + (y * m_pitch) + x) = data;
			return;
		}
		else if (m_numChannels == 2) {
			cout << "1)R" << endl;
			cout << "2)G" << endl;
			cin >> answer;

			if (answer == '1') {
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) = data;
			}
			else {
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) = data;

			}
			return;
		}
		else if (m_numChannels == 3) {
			cout << "1)R" << endl;
			cout << "2)G" << endl;
			cout << "3)B" << endl;
			cin >> answer;
			if (answer == '1') {
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) = data;
			}
			else if (answer == '2') {
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) = data;
			}
			else {
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 2) = data;
			}
			return;
		}
		else if (m_numChannels == 4) {
			cout << "1)R" << endl;
			cout << "2)G" << endl;
			cout << "3)B" << endl;
			cout << "4)A" << endl;
			cin >> answer;
			if (answer == '1') {
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) = data;
			}
			else if (answer == '2') {
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) = data;
			}
			else if (answer == '3') {
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 2) = data;
			}
			else {
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 3) = data;
			}
			return;
		}
	}
}

bool CBuffer::isDatainCoord(const int & x, const int & y)
{
	if (m_format <= RGBAUN8) {
		if (m_numChannels == 1) {
			if (
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) != '\0'
				)
				return true;
			else {
				return false;
			}

		}
		else if (m_numChannels == 2) {
			if (
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) != '\0'
				|| *((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) != '\0')
				return true;
			else {
				return false;
			}
		}
		else if (m_numChannels == 3) {
			if (
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) != '\0'
				|| *((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) != '\0'
				|| *((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 2) != '\0')
				return true;
			else {
				return false;
			}
		}
		else {
			if (
				*((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) != '\0'
				|| *((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) != '\0'
				|| *((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 2) != '\0'
				|| *((unsigned char*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 3) != '\0')
				return true;
			else {
				return false;
			}
		}
	}
	else {
		if (m_numChannels == 1) {
			if (
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) != 0
				)
				return true;
			else {
				return false;
			}

		}
		else if (m_numChannels == 2) {
			if (
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) != 0
				|| *((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) != 0)
				return true;
			else {
				return false;
			}
		}
		else if (m_numChannels == 3) {
			if (
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) != 0
				|| *((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) != 0
				|| *((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 2) != 0)
				return true;
			else {
				return false;
			}
		}
		else {
			if (
				*((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels)) != 0
				|| *((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 1) != 0
				|| *((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 2) != 0
				|| *((float*)m_Buffer + (y * m_pitch) + (x * m_numChannels) + 3) != 0)
				return true;
			else {
				return false;
			}
		}
	}
}

void CBuffer::drawAlgebraicLine(const int & x1, const int & y1, const int & x2, const int & y2)
{
	if (m_format == NotAFormat) {
		clearBuffer();
		if (x1 >= m_width && x2 >= m_width) {
			cout << "buffer overflow" << endl;
			return;
		}
		if (y1 >= m_width && y2 >= m_width) {
			cout << "buffer overflow" << endl;
			return;
		}

		cout << "Ecuacíon de la recta" << endl;
		*((unsigned char *)m_Buffer + ((m_height - y1 - 1) * m_pitch) + x1) = '*';
		*((unsigned char *)m_Buffer + (((m_height - y2 - 1) * m_pitch) + x2)) = '*';

		

		float m = (float) (y2 - y1) / (x2 - x1); // y = mx +b, b = y-mx
		float b = y1 - (m * x1);


		int y = 0;
		for (int i = x1 + 1; i < x2; i++) {
			y = (m * i) + b;
			*((unsigned char *)m_Buffer + ((m_height - y - 1) * m_pitch) + i) = '*';
		}

		printBuffer();
		cout << endl;
	}
	else {
		cout << "Buffer must not have a format to draw forms" << endl;
		return;
	}
}

void CBuffer::drawBresenhamLine(const int & x1, const int & y1, const int & x2, const int & y2)
{
	clearBuffer();
	cout << "Linea de bresenham" << endl;

	int m_b = 2 * (y2 - y1);
	int error = m_b - (x2 - x1);

	int y = y1;
	for (int i = x1; i <= x2; i++)
	{
		//cout << "(" << x << "," << y << ")\n";
		error += m_b;
		*((unsigned char *)m_Buffer + ((m_height - y - 1) * m_pitch) + i) = '*';
		if (error >= 0)
		{
			y++;
			error -= 2 * (x2 - x1);
		}
	}
	printBuffer();
	cout << endl;
}

void CBuffer::drawAlgegraicCircle(const int & radius)
{
	clearBuffer();
	int N = 2 * radius + 1;

	int x; 
	int y;

	 
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			
			x = j - radius;
			y = i - radius;
			/*cout << x * x << endl;
			cout << y * y << endl;*/
			if (x*x + y * y <= radius * radius + 1) {
				*((unsigned char*)m_Buffer + (j * m_pitch) + i) = '.';
			}
		}
	}
	printBuffer();
}


void CBuffer::copyBuffer(CBuffer & buffer)
{
	
	if ((m_format == R8 && (buffer.getFormat() <= RGBAUN8)) || ((m_format <= RGBAUN8) && (buffer.getFormat() == R8))) {//caso para copiar de un formato rgba8 a un r8 o viceversa
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x,y)) {
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
				}
			}
		}
		return;
	}
	else if (m_format == R8 && (buffer.getFormat() <= RGBAF32)) { //caso para copiar de cualquier formato de 32 bits a R8
		float change = 0.0f;
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x, y)) {
					change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					change *= 255.0f;
					change = floorf(change);
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;
				}
			}
		}
		return;
	}
	else if ((m_format == RG8 && buffer.getFormat() <= RGBAUN8) || (m_format <= RGBAUN8 && buffer.getFormat() == RG8)) {//casos para los formatos de 8 bits de 2 o más canales
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x, y)) {
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
				}
			}
		}
		return;
	}
	else if (m_format == RG8 && buffer.getFormat() <= RGBAF32) {
		if (buffer.getNumChannels() == 1) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;
					}
				}
			}
			return;
		}
		else {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;
					}
					
				}
			}
			return;
		}
	}
	else if ((m_format == RGB8 && buffer.getFormat() <= RGBAUN8) || (m_format <= RGBAUN8 && buffer.getFormat() == RGB8)) { //casos para formatos de 8 bits de 3 y 4 canales
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x, y)) {
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
				}
			}
		}
		return;
	}
	else if (m_format == RGB8 && buffer.getFormat() <= RGBAF32) {
		if (buffer.getNumChannels() == 1) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
					change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					change *= 255.0f;
					change = floorf(change);
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;
					}
				}
			}	
		return;
		}
		else if(buffer.getNumChannels() == 2) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;
					}

				}
			}
			return;
		}
		else if (buffer.getNumChannels() == 3) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;


						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = change;
					}

				}
			}
			return;
		}
	}
	else if (m_format == RGBAUN8 && buffer.getFormat() == RGBAUN8) {
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x, y)) {
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 3) = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 3);

				}
			}
		}
		return;
	}
	else if(m_format == RGBAUN8 && buffer.getFormat() <= RGBAF32) {
		if (buffer.getNumChannels() == 1) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
					change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					change *= 255.0f;
					change = floorf(change);
					*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;
					}
				}
			}	
		return;
		}
		else if(buffer.getNumChannels() == 2) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;
					}

				}
			}
			return;
		}
		else if (buffer.getNumChannels() == 3) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;


						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = change;
					}

				}
			}
			return;
		}
		else if (buffer.getNumChannels() == 4) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;


						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;


						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = change;


						change = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 3);
						change *= 255.0f;
						change = floorf(change);
						*((unsigned char *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 3) = change;
					}

				}
			}
			return;
		}
	}
	/*
	
	Formatos de 32 bits 
	
	*/

	if ((m_format == RF32 && (buffer.getFormat() > RGBAF32)) || ((m_format > RGBAF32) && (buffer.getFormat() == RF32))) {//caso para copiar de un formato de 32 bits a un rf32 o viceversa
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x, y)) {
					*((float *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = *(((float *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
				}
			}
		}
		return;
	}
	else if (m_format == RF32 && (buffer.getFormat() <= RGBAUN8)) { //caso para copiar de cualquier formato de 8 bits a Rf32
		float change = 0.0f;
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x, y)) {
					change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					change /= 255.0f;
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;
				}
			}
		}
		return;
	}
	else if ((m_format == RGF32 && buffer.getFormat() >= RGF32) || (m_format >= RGF32 && buffer.getFormat() == RGF32)) {//casos para los formatos de 32 bits de 2 o más canales
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x, y)) {
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
				}
			}
		}
		return;
	}
	else if (m_format == RGF32 && buffer.getFormat() <= RGBAUN8) {
		if (buffer.getNumChannels() == 1) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change /= 255.0f;
						*((float *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;
					}
				}
			}
			return;
		}
		else {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change /= 255.0f;
						*((float *)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((unsigned char *)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change /= 255.0f;
						*((float *)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;
					}

				}
			}
			return;
		}
	}
	else if ((m_format == RGBF32 && buffer.getFormat() >= RGBF32) || (m_format >= RGBF32 && buffer.getFormat() == RGBF32)) { //casos para formatos de 32 bits de 3 y 4 canales
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x, y)) {
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
				}
			}
		}
		return;
	}
	else if (m_format == RGBF32 && buffer.getFormat() <= RGBAUN8) {
		if (buffer.getNumChannels() == 1) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;
					}
				}
			}
			return;
		}
		else if (buffer.getNumChannels() == 2) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;
					}

				}
			}
			return;
		}
		else if (buffer.getNumChannels() == 3) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;


						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = change;
					}

				}
			}
			return;
		}
	}
	else if (m_format == RGBAF32 && buffer.getFormat() == RGBAF32) { //pasarse informacion entre 4 canales de 32 bits
		float n = 1.0f / m_width;
		float x = 0.0f;
		float y = 0.0f;
		for (int j = 0; j < m_height; j++) {
			y = n * j*buffer.getHeight();
			y = floorf(y);
			for (int i = 0; i < m_width; i++) {
				x = n * i*buffer.getWidth();
				x = floor(x);
				//cout << "coord x: " << x << " coord y: " << y << endl;
				if (buffer.isDatainCoord(x, y)) {
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
					*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 3) = *(((float*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 3);

				}
			}
		}
		return;
	}
	else if (m_format == RGBAF32 && buffer.getFormat() <= RGBAUN8) { //pasar informacion de 4 canales de 32 bits a cualquiera de 8 bits
		if (buffer.getNumChannels() == 1) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;
					}
				}
			}
			return;
		}
		else if (buffer.getNumChannels() == 2) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;
					}

				}
			}
			return;
		}
		else if (buffer.getNumChannels() == 3) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;

						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;


						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = change;
					}

				}
			}
			return;
		}
		else if (buffer.getNumChannels() == 4) {
			float change = 0.0f;
			float n = 1.0f / m_width;
			float x = 0.0f;
			float y = 0.0f;
			for (int j = 0; j < m_height; j++) {
				y = n * j*buffer.getHeight();
				y = floorf(y);
				for (int i = 0; i < m_width; i++) {
					x = n * i*buffer.getWidth();
					x = floor(x);
					//cout << "coord x: " << x << " coord y: " << y << endl;
					if (buffer.isDatainCoord(x, y)) {
						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())));
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch))) = change;


						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 1);
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 1) = change;


						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 2);
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 2) = change;


						change = *(((unsigned char*)buffer.getPointer() + ((int)y* buffer.getPitch()) + ((int)x * buffer.getNumChannels())) + 3);
						change /= 255.0f;
						*((float*)m_Buffer + ((i * m_numChannels) + (j * m_pitch)) + 3) = change;
					}

				}
			}
			return;
		}
	}


}
