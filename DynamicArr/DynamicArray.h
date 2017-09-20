#pragma once
class DynamicArray
{

public:
	DynamicArray();
	~DynamicArray();

	void pushBack(int val);
	int SelectElem(int index);
	void setSize(int _size);

private:

	void ArrayGrow();

	int bufferSize =0;

	int *buffer;
	
	int arrSize=0;
};

