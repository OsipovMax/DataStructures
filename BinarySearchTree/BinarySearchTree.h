#pragma once

#include <memory>
#include <iostream>
#include <queue>
#include <stack>

class iterator {};

template <typename T1, typename T2>
class BinarySearchTree {
public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(const T1&);
	// BFS method
	void printTree();
	// Iterative methods
	void preOrderShow();
	void inOrderShow();
	void postOrderShow();

	T2& find(const T1&);
	void clear();
	void erase(const T1&);

	T2& operator[](const T1& desiredKey) {
		bool is_contain = false;
		node tempNode = find(desiredKey, is_contain);

		if (!is_contain || tempNode == nullptr) {
			std::cout << "non element" << std::endl;
			return *(new T2());
		}
		return tempNode->val;
	}

private:
	struct BstNode {
		using ptrNode = std::shared_ptr<BstNode>;

		BstNode(T1 _key, T2 _val, ptrNode _leftChild = nullptr,
			ptrNode _rightChild = nullptr, ptrNode _parent = nullptr)
			: parent(_parent),
			leftChild(_leftChild),
			rightChild(_rightChild),
			key(_key),
			val(_val) {}

		ptrNode parent;
		ptrNode leftChild;
		ptrNode rightChild;
		T1 key;
		T2 val;
	};

	typedef typename BstNode::ptrNode node;

	node find(const T1&, bool&);
	node min(const node);

	int treeSize;
	node root, link;
};

template <typename T1, typename T2>
BinarySearchTree<T1, T2>::BinarySearchTree() {}

template <typename T1, typename T2>
BinarySearchTree<T1, T2>::~BinarySearchTree() {}

template <typename T1, typename T2>
void BinarySearchTree<T1, T2>::insert(const T1& insertKey) {
	node currentNode, parentNode;
	auto newNode = std::make_shared<BstNode>(insertKey, insertKey * 3);

	if (root == nullptr) {
		root = newNode;
		return;
	}
	currentNode = root;
	while (currentNode != nullptr) {
		if (insertKey >= currentNode->key) {
			parentNode = currentNode;
			currentNode = currentNode->rightChild;
		}
		else {
			parentNode = currentNode;
			currentNode = currentNode->leftChild;
		}
	}
	if (parentNode->key > newNode->key) {
		parentNode->leftChild = newNode;
	}
	else {
		parentNode->rightChild = newNode;
	}
	newNode->parent = parentNode;
}

// BFS method
template <typename T1, typename T2>
void BinarySearchTree<T1, T2>::printTree() {
	node currentNode;
	std::queue<node> tempQueue;
	if (root == nullptr) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}
	tempQueue.push(root);
	while (tempQueue.size() != 0) {
		currentNode = tempQueue.front();
		tempQueue.pop();
		std::cout << currentNode->key << " ";
		if (currentNode->leftChild != nullptr)
			tempQueue.push(currentNode->leftChild);
		if (currentNode->rightChild != nullptr)
			tempQueue.push(currentNode->rightChild);
	}
	std::cout << std::endl;
}

template <typename T1, typename T2>
void BinarySearchTree<T1, T2>::preOrderShow() {
	std::stack<node> s;
	node visitedNode;
	if (root == nullptr) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}
	s.push(root);
	while (!s.empty()) {
		visitedNode = s.top();
		s.pop();
		std::cout << visitedNode->key << " ";
		if (visitedNode->rightChild) {
			s.push(visitedNode->rightChild);
		}
		if (visitedNode->leftChild) {
			s.push(visitedNode->leftChild);
		}
	}
	std::cout << std::endl;
}

template <typename T1, typename T2>
void BinarySearchTree<T1, T2>::inOrderShow() {
	std::stack<node> s;
	node currentNode;
	if (root == nullptr) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}
	currentNode = root;
	while (!s.empty() || currentNode != nullptr) {
		if (currentNode) {
			s.push(currentNode);
			currentNode = currentNode->leftChild;
		}
		else {
			currentNode = s.top();
			s.pop();
			std::cout << currentNode->key << " ";
			currentNode = currentNode->rightChild;
		}
	}
	std::cout << std::endl;
}

template <typename T1, typename T2>
void BinarySearchTree<T1, T2>::postOrderShow() {
	std::stack<node> s;
	node currentNode, lastVisitedNode, previousNode;
	if (root == nullptr) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}
	currentNode = root;
	while (!s.empty() || currentNode != nullptr) {
		if (currentNode) {
			s.push(currentNode);
			currentNode = currentNode->leftChild;
		}
		else {
			previousNode = s.top();
			if (previousNode->rightChild != nullptr &&
				previousNode->rightChild != lastVisitedNode) {
				currentNode = previousNode->rightChild;
			}
			else {
				std::cout << previousNode->key << " ";
				lastVisitedNode = s.top();
				s.pop();
			}
		}
	}
	std::cout << std::endl;
}
template <typename T1, typename T2>
typename BinarySearchTree<T1, T2>::node BinarySearchTree<T1, T2>::find(
	const T1& desiredKey, bool& is_contain) {
	node currentNode;
	std::queue<node> q;
	q.push(root);

	if (root == nullptr) {
		is_contain = false;
		return nullptr;
	}

	while (!q.empty()) {
		currentNode = q.front();
		q.pop();
		if (currentNode->key == desiredKey) {
			is_contain = true;
			break;
		}

		if (currentNode->leftChild != nullptr) {
			q.push(currentNode->leftChild);
		}
		if (currentNode->rightChild != nullptr) {
			q.push(currentNode->rightChild);
		}
	}

	if (currentNode->key != desiredKey) {
		return nullptr;
	}
	return currentNode;
}

template <typename T1, typename T2>
typename BinarySearchTree<T1, T2>::node BinarySearchTree<T1, T2>::min(
	node _root) {
	if (_root->leftChild == nullptr) {
		return _root;
	}
	return min(_root->leftChild);
}
template <typename T1, typename T2>
T2& BinarySearchTree<T1, T2>::find(const T1& desiredKey) {
	bool is_contain = false;

	node resultNode = find(desiredKey, is_contain);

	if (!is_contain) {
		std::cout << " non element " << std::endl;
	}
	return resultNode->val;
}

template <typename T1, typename T2>
void BinarySearchTree<T1, T2>::clear() {
	std::stack<node> s;
	node currentNode, lastVisitedNode, previousNode;
	currentNode = root;

	while (!s.empty() || currentNode != nullptr) {
		if (currentNode != nullptr) {
			s.push(currentNode);
			currentNode = currentNode->leftChild;
		}
		else {
			previousNode = s.top();
			if (previousNode->rightChild != nullptr &&
				previousNode->rightChild != lastVisitedNode) {
				currentNode = previousNode->rightChild;
			}
			else {
				lastVisitedNode = s.top();
				s.pop();
				lastVisitedNode->leftChild.reset();
				lastVisitedNode->rightChild.reset();
			}
		}
	}
	root.reset();
}

template <typename T1, typename T2>
void BinarySearchTree<T1, T2>::erase(const T1& deleteItem) {
	bool is_contain = false;
	node ersElement = find(deleteItem, is_contain);

	if (!is_contain) {
		std::cout << "non element" << std::endl;
		return;
	}

	if (ersElement->leftChild == nullptr && ersElement->rightChild == nullptr) {
		if (ersElement->parent->key > ersElement->key) {
			ersElement->parent->leftChild = nullptr;
		}
		else {
			ersElement->parent->rightChild = nullptr;
		}
		ersElement = nullptr;
		return;
	}

	if (ersElement->leftChild == nullptr) {
		if (ersElement->parent->key > ersElement->key) {
			ersElement->parent->leftChild = ersElement->rightChild;
		}
		else {
			ersElement->parent->rightChild = ersElement->rightChild;
		}
		ersElement->rightChild->parent = ersElement->parent;
		ersElement = nullptr;
		return;
	}

	if (ersElement->rightChild == nullptr) {
		if (ersElement->parent->key > ersElement->key) {
			ersElement->parent->leftChild = ersElement->leftChild;
		}
		else {
			ersElement->parent->rightChild = ersElement->leftChild;
		}
		ersElement->leftChild->parent = ersElement->parent;
		ersElement = nullptr;
		return;
	}

	if (ersElement->rightChild != nullptr && ersElement->leftChild != nullptr) {
		node temp = min(ersElement);
		ersElement->val = temp->val;
		ersElement->key = temp->key;
		temp->parent->leftChild = temp->rightChild;
		if (temp->rightChild != nullptr) {
			temp->rightChild->parent = temp->parent;
		}
		temp->parent->leftChild = nullptr;
		temp = nullptr;
	}
}