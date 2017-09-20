#include "stdafx.h"
#include "DynamicArray.h"


DynamicArray::DynamicArray()
{
}


DynamicArray::~DynamicArray()
{
}

void DynamicArray::setSize(int _size) {
	this->bufferSize = _size;
	buffer = new int[bufferSize];
}

void DynamicArray::ArrayGrow() {
	int newBufferSize = bufferSize * 2;
	int * newBuffer = new int[newBufferSize];
	for (int i = 0; i < bufferSize; i++)
		newBuffer[i] = buffer[i];
	delete[] buffer;
	buffer = newBuffer;
	bufferSize = newBufferSize;
}

void DynamicArray::pushBack(int val) {
	if (bufferSize == arrSize)
		ArrayGrow();
	buffer[arrSize++] = val;
}

int DynamicArray::SelectElem(int index) {
	return buffer[index];
}