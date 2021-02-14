#include "tree.hpp"

#include <iostream>

template <class T> Node<T>::Node(T key, Node<T>* parent) {
	this->key = key;
	this->parent = parent;
	leftChild = NULL;
	rightChild = NULL;
}

template <class T> Tree<T>::Tree() {
	root_ = NULL;
}

template <class T> Tree<T>::~Tree() {
	removeTree(root_);
}

template <class T> void Tree<T>::insert(T key) {
	Node<T>* ptr = root_;
	Node<T>* parentPtr = NULL;
	while(ptr!=NULL) {
		parentPtr = ptr;
		int sorceCompare = compare(key, ptr->key);
		if(sorceCompare==0) {
			throw 0;
		} else if(sorceCompare==1) {
			ptr = ptr->rightChild;
		} else {
			ptr = ptr->leftChild;
		}
	}
	ptr = new Node<T>(key, parentPtr);
	if(parentPtr==NULL) {
		root_ = ptr;
	} else if(compare(key, parentPtr->key)){
		parentPtr->rightChild = ptr;
	} else {
		parentPtr->leftChild = ptr;
	}
}

template <class T> T Tree<T>::remove(T key) {
	Node<T>* ptr = findNode(key);
	if(ptr==NULL) throw 0;
	remove(ptr);
	T score = ptr->key;
	delete ptr;
	return score;
}

template <class T> T Tree<T>::find(T key) {
	Node<T>* ptr = root_;
	while(ptr!=NULL) {
		int scoreCompare = compare(key, ptr->key);
		if(scoreCompare==0) {
			return ptr->key;
		} else if(scoreCompare==1) {
			ptr = ptr->rightChild;
		} else {
			ptr = ptr->leftChild;
		}
	}
	throw 0;
}

template <class T> Node<T>* Tree<T>::findNode(T key) {
	Node<T>* ptr = root_;
	while(ptr!=NULL) {
		int scoreCompare = compare(key, ptr->key);
		if(scoreCompare==0) {
			return ptr;
		} else if(scoreCompare==1) {
			ptr = ptr->rightChild;
		} else {
			ptr = ptr->leftChild;
		}
	}
	return NULL;
}

template <class T> Node<T>* Tree<T>::remove(Node<T>* ptr) {
	Node<T>* newPtr = NULL;
	if(ptr!=NULL) {
		if(ptr->leftChild!=NULL && ptr->rightChild!=NULL) {
			newPtr = remove(pred(ptr));
			newPtr->leftChild = ptr->leftChild;
			if(newPtr->leftChild) {
				newPtr->leftChild->parent = newPtr;
			}
			newPtr->rightChild = ptr->rightChild;
			if(newPtr->rightChild) {
				newPtr->rightChild->parent = newPtr;
			}
		} else if(ptr->leftChild!=NULL) {
			newPtr = ptr->leftChild;
		} else {
			newPtr = ptr->rightChild;
		}
		if(newPtr) {
			newPtr->parent = ptr->parent;
		}
		if(ptr->parent==NULL) {
			root_ = newPtr;
		} else if(ptr->parent->leftChild == ptr) {
			ptr->parent->leftChild = newPtr;
		} else {
			ptr->parent->rightChild = newPtr;
		}
	}
	return ptr;
}

template <class T> void Tree<T>::removeTree(Node<T>* root) {
	if(root==NULL) return;
	if(root->rightChild!=NULL) removeTree(root->rightChild);
	if(root->leftChild!=NULL) removeTree(root->leftChild);
	delete root;
}

template <class T> Node<T>* Tree<T>::pred(Node<T>* ptr) {
	if(ptr==NULL) return NULL;
	Node<T>* pred = ptr->leftChild;
	if(pred!=NULL) {
		while(pred->rightChild!=NULL) {
			pred = pred->rightChild;
		}
	} else {
		pred = ptr;
		while(pred->parent!=NULL&&pred->parent->rightChild!=pred) {
			pred = pred->parent;
		}
		pred = pred->parent;
	}
	return pred;
}

template <class T> Node<T>* Tree<T>::succ(Node<T>* ptr) {
	if(ptr==NULL) return NULL;
	Node<T>* succ = ptr->rightChild;
	if(succ!=NULL) {
		while(succ->leftChild!=NULL) {
			succ = succ->leftChild;
		}
	} else {
		succ = ptr;
		while(succ->parent!=NULL&&succ->parent->leftChild!=succ) {
			succ = succ->parent;
		}
		succ = succ->parent;
	}
	return succ;
}
