// TreeB.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct treeNode {
	int node;
	treeNode* LeftChild;
	treeNode* RightChild;
};

void addNode(const int &data,  treeNode* &element) {

	if (element == NULL) {
		element = new treeNode;
		element->node = data;
		element->LeftChild = NULL;
		element->RightChild = NULL;
		return;
	}
	if (element->node > data) {
		addNode(data, element->LeftChild);
	}
	else {
		addNode(data, element->RightChild);
	}
}
int tabs = 0;// значение уровня узла
void PrintTree(treeNode* &element) {

	if (element == NULL)
		return;
	tabs++;

	PrintTree(element->LeftChild);
	//for (int i = 0; i < tabs; i++) cout << " ";
	cout << element->node << endl;

	PrintTree(element->RightChild);

	tabs--;
	
}
void DeleteTree(treeNode* &element) {
	if (element == NULL) return;
	DeleteTree(element->LeftChild);
	DeleteTree(element->RightChild);
	delete element;
}

void Serach(treeNode* &element, int num) {
	if (element == NULL)
		//cout << "error" << endl;
		return;
	if (num > element->node) {
		Serach(element->RightChild, num);
	}
	else if (num < element->node) {
		Serach(element->LeftChild, num);
	}
	else {
		cout << "true" << endl;;
		cout << "!!!" << element->node;
	}

}
int main()
{
	treeNode* root= NULL;
	vector <int > arr = { 9,2,7,11,1 };
	for (int j = 0; j < arr.size(); j++) {
		addNode(arr[j], root);
	}
	PrintTree(root);
	Serach(root, 1);
	cin.get();
	system("pause");
	return 0;
}

