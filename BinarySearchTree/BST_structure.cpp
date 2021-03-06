#include "BinarySearchTree.h"
#include <iostream>
#include <array>

int main() {
	BinarySearchTree<int,int> A;
	std::array<int, 7> testArr{3, 5, 4, 2, 1, 7, 9};
	for (size_t i = 0; i < testArr.size(); ++i) {
		A.insert(testArr[i]);
	}

	A.printTree();
	A.preOrderShow();
	A.inOrderShow();
	A.postOrderShow();
	A.erase(3);
	int h = A[33];
	std::cout << h << std::endl;
    h = A.find(7);
	std::cout << h << std::endl;
	A.printTree();
}