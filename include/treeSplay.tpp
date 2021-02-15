#include "treeSplay.hpp"

template <class T> bool TreeSplay<T>::insert(T key) {
	if(this->root_==NULL) {
		this->root_ = new Node<T>(key, NULL, NULL);
	} else {
		find(key);
		int scoreCompare = compare(key, this->root_->key);
		if(scoreCompare == 0) {
			return false;
		} else if(scoreCompare == 1) {
			this->root_ = new Node<T>(key, this->root_, this->root_->rightChild);
		} else {
			this->root_ = new Node<T>(key, this->root_->leftChild, this->root_);
		}
		if(this->root_->leftChild) this->root_->leftChild->parent = this->root_;
		if(this->root_->rightChild) this->root_->rightChild->parent = this->root_;
	}
	return true;
}

template <class T> T* TreeSplay<T>::find(T key) {
	Node<T>* ptr = findNode(key);
	if(ptr==NULL) return NULL;
	splay(ptr);
	return &this->root_->key;
}

template <class T> T* TreeSplay<T>::remove(T key) {
	Node<T>* ptr = findNode(key);
	if(ptr==NULL||compare(key, ptr->key)!=0) return NULL;
	remove(ptr);
	T score = ptr->key;
	delete ptr;
	return &score;
}

template <class T> void TreeSplay<T>::R(Node<T>* ptr) {
	if(ptr==NULL) throw 0;
	Node<T>* newPtr = ptr->leftChild;
	if(newPtr==NULL) throw 0;
	if(ptr->parent==NULL) this->root_ = newPtr;
	else if(ptr->parent->leftChild==ptr) ptr->parent->leftChild = newPtr;
	else ptr->parent->rightChild = newPtr;
	newPtr->parent = ptr->parent;
	ptr->leftChild = newPtr->rightChild;
	if(ptr->leftChild!=NULL) ptr->leftChild->parent = ptr;
	newPtr->rightChild = ptr;
	ptr->parent = newPtr;
}

template <class T> void TreeSplay<T>::L(Node<T>* ptr) {
	if(ptr==NULL) throw 0;
	Node<T>* newPtr = ptr->rightChild;
	if(newPtr==NULL) throw 0;
	if(ptr->parent==NULL) this->root_ = newPtr;
	else if(ptr->parent->leftChild==ptr) ptr->parent->leftChild = newPtr;
	else ptr->parent->rightChild = newPtr;
	newPtr->parent = ptr->parent;
	ptr->rightChild = newPtr->leftChild;
	if(ptr->rightChild!=NULL) ptr->rightChild->parent = ptr;
	newPtr->leftChild = ptr;
	ptr->parent = newPtr;
}

template <class T> void TreeSplay<T>::splay(Node<T>* ptr) {
	while(ptr->parent!=NULL) {
		if(ptr->parent->parent==NULL) {
			if(ptr->parent->leftChild==ptr) {
				R(ptr->parent);
			} else {
				L(ptr->parent);
			}
		} else if(ptr->parent->parent->leftChild==ptr->parent) {
			if(ptr->parent->leftChild==ptr) {
				R(ptr->parent->parent);
			} else {
				L(ptr->parent);
			}
			R(ptr->parent);
		} else {
			if(ptr->parent->rightChild==ptr) {
				L(ptr->parent->parent);
			} else {
				R(ptr->parent);
			}
			L(ptr->parent);
		}
	}
}

template <class T> Node<T>* TreeSplay<T>::remove(Node<T>* ptr) {
	if(ptr!=NULL) {
		splay(ptr);
		this->root_ = ptr->leftChild;
		if(this->root_!=NULL) {
			this->root_->parent = NULL;
			find(ptr->key);
			this->root_->rightChild = ptr->rightChild;
			if(this->root_->rightChild!=NULL) this->root_->rightChild->parent = this->root_;
		} else {
			this->root_ = ptr->rightChild;
			if(this->root_!=NULL) this->root_->parent = NULL;
		}
	}
	return ptr;
}

template <class T> Node<T>* TreeSplay<T>::findNode(T key) {
	Node<T>* ptr = this->root_;
	Node<T>* parentPtr = NULL;
	while(ptr!=NULL) {
		parentPtr = ptr;
		int scoreCompare = compare(key, ptr->key);
		if(scoreCompare==0) {
			return ptr;
		} else if(scoreCompare==1) {
			ptr = ptr->rightChild;
		} else {
			ptr = ptr->leftChild;
		}
	}
	return parentPtr;
}
