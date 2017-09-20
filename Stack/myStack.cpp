// myStack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdlib>
#include "mStack.h"
#include <vector>
struct stack {
	struct node {
		int data;
		node *ptr;
	};
	node* top=NULL;

	void addNode(int num);
	void pop();
	int _top();
};

void stack::addNode(int num) {
	if (top == NULL) {
		top = new node;
		top->data = num;
	}
	else {
		node* tempNode = new node;
		tempNode->data = num;
		tempNode->ptr = top;
		top = tempNode;

	}

}
void stack::pop() {
	if (top == NULL)
		cout << "error";
	else {
		node* tempNode = new node;
		tempNode = top->ptr;
		delete top;
		top = tempNode;

	}
}
int stack::_top() {
	return top->data;
}
int main()
{   
	stack myStack;

	vector < int > arr = { 3,5,7,2 };
	for (int i = 0; i < arr.size(); i++)
		myStack.addNode(arr[i]);
	cout << myStack._top() << endl;;
	myStack.pop();
	cout << myStack._top() << endl;
	system("pause");
	return 0;
}

