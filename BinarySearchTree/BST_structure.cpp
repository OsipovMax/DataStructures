#include "BinarySearchTree.h"
#include <iostream>
#include <array>

int main() {
	BinarySearchTree<int> A;
	std::array<int, 5> testArr{3, 5, 2, 1, 7};
	for (size_t i = 0; i < testArr.size(); ++i) {
		A.insert(testArr[i]);
	}

	A.printTree();
	A.preOrderShow();
	A.inOrderShow();
	A.postOrderShow();
}