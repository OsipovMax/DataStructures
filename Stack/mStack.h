#pragma once
#include <vector>
#include <iostream>
using namespace std;
template <class inputType>
class mStack
{

public:
	mStack();
	~mStack();

	void push(const inputType& val);
	void pop();
	long long int size();
	inputType top();

private:
	vector <int> stack;

};


template<class inputType>
mStack<inputType>::mStack()
{
}

template <class inputType>
mStack<inputType>::~mStack()
{
}
template <class inputType>
void mStack<inputType>::push(const inputType& val) {
	if (stack.max_size() > stack.size())
		stack.push_back(val);
	else cout << "error";
}

template <class inputType>
void mStack<inputType>::pop() {
	stack.pop_back();
}

template<class inputType>
long long int mStack<inputType>::size() {
	return stack.size();
}

template<class inputType>
inputType mStack<inputType>::top() {
	return stack.back();
}