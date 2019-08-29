#pragma once

#include <memory>
#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class BinarySearchTree {
public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(const T &);
	// BFS method
	void printTree();
	// Iterative methods
	void preOrderShow();
	void inOrderShow();
	void postOrderShow();

private:
	struct BstNode {
		using ptrNode = std::shared_ptr<BstNode>;

		BstNode(const T &_key, ptrNode _leftChild = nullptr,
			ptrNode _rightChild = nullptr)
			: leftChild(_leftChild), rightChild(_rightChild), key(_key) {}
		ptrNode parent;
		ptrNode leftChild;
		ptrNode rightChild;
		const T &key;
	};

	int treeSize;
	typedef typename BstNode::ptrNode node;
	node root, link;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
	// root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {}

template <typename T>
void BinarySearchTree<T>::insert(const T &insertKey) {
	node currentNode, parentNode;
	auto newNode = std::make_shared<BstNode>(insertKey);

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
template <typename T>
void BinarySearchTree<T>::printTree() {
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

template <typename T>
void BinarySearchTree<T>::preOrderShow() {
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

template <typename T>
void BinarySearchTree<T>::inOrderShow() {
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

template <typename T>
void BinarySearchTree<T>::postOrderShow() {
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