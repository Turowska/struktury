#include "treeAVL.hpp"

template <class T> NodeAVL<T>::NodeAVL(T key, NodeAVL<T>* parent): Node<T>(key, parent) {
	bf = 0;
}

template <class T> bool TreeAVL<T>::insert(T key) {
	NodeAVL<T>* ptr = (NodeAVL<T>*) this->root_;
	NodeAVL<T>* parentPtr = NULL;
	
//wstawianie węzła
	while(ptr) {
		parentPtr = ptr;
		int scoreCompare = compare(key, ptr->key);
		if(scoreCompare==0) {
			return false;
		} else if(scoreCompare==1) {
			ptr = (NodeAVL<T>*) ptr->rightChild;
		} else {
			ptr = (NodeAVL<T>*) ptr->leftChild;
		}
	}
	ptr = new NodeAVL<T>(key, parentPtr);
	if(parentPtr==NULL) {
		this->root_ = ptr;
	} else if(compare(key, parentPtr->key)==1) {
		parentPtr->rightChild = ptr;
		--parentPtr->bf;
	} else {
		parentPtr->leftChild = ptr;
		++parentPtr->bf;
	}
//zrównoważenie
	while(parentPtr) {
		if(parentPtr->bf==0) return true;
		if(parentPtr->bf==2) {
			if(ptr->bf==-1) LR((NodeAVL<T>*) parentPtr);
			else LL((NodeAVL<T>*) parentPtr);
			return true;
		} else if(parentPtr->bf==-2) {
			if(ptr->bf==1) RL((NodeAVL<T>*) parentPtr);
			else RR((NodeAVL<T>*) parentPtr);
			return true;
		}
		parentPtr = (NodeAVL<T>*) parentPtr->parent;
		ptr = (NodeAVL<T>*) ptr->parent;
	}
	return true;
}

template <class T> void TreeAVL<T>::RR(NodeAVL<T>* ptr) {
	if(ptr==NULL) throw 0;
	NodeAVL<T>* rightChild = (NodeAVL<T>*) ptr->rightChild;
	if(rightChild==NULL) throw 0;
	NodeAVL<T>* parent = (NodeAVL<T>*) ptr->parent;
//wskaźniki
	ptr->rightChild = (NodeAVL<T>*) rightChild->leftChild;
	if(ptr->rightChild) ptr->rightChild->parent = ptr;
	rightChild->leftChild = ptr;
	rightChild->parent = parent;
	ptr->parent = rightChild;
	if( parent )
	{
		if( parent->leftChild == ptr ) parent->leftChild = rightChild;
		else parent->rightChild = rightChild;
	} else this->root_ = rightChild;
//bf
	int bfNode = -(rightChild->bf);
	if(bfNode <0){
		bfNode=0;
	}
	bfNode += 1 + ptr->bf;
	int bfChild = bfNode;
	if(bfChild<0){
		bfChild = 0;
	}
	bfChild += 1 + rightChild->bf;
	ptr->bf = bfNode;
	rightChild->bf = bfChild;
}

template <class T> void TreeAVL<T>::LL(NodeAVL<T>* ptr) {
	if(ptr==NULL) throw 0;
	NodeAVL<T>* leftChild = (NodeAVL<T>*) ptr->leftChild;
	if(leftChild==NULL) throw 0;
	NodeAVL<T>* parent = (NodeAVL<T>*) ptr->parent;
//wskaźniki
	ptr->leftChild = (NodeAVL<T>*) leftChild->rightChild;
	if( ptr->leftChild ) ptr->leftChild->parent = ptr;
	leftChild->rightChild = ptr;
	leftChild->parent = parent;
	ptr->parent = leftChild;
	if( parent )
	{
		if( parent->leftChild == ptr ) parent->leftChild = leftChild;
		else parent->rightChild = leftChild;
	} else this->root_ = leftChild;
//bf
	int bfNode = -(leftChild->bf);
	if(bfNode>0){
		bfNode=0;
	}
	bfNode += ptr->bf - 1;
	int bfChild = bfNode;
	if(bfChild>0){
		bfChild = 0;
	}
	bfChild += leftChild->bf -1;
	ptr->bf = bfNode;
	leftChild->bf = bfChild;
}

template <class T> void TreeAVL<T>::LR(NodeAVL<T>* ptr) {
	RR((NodeAVL<T>*) ptr->leftChild);
	LL((NodeAVL<T>*) ptr);
}

template <class T> void TreeAVL<T>::RL(NodeAVL<T>* ptr) {
	LL((NodeAVL<T>*) ptr->rightChild);
	RR((NodeAVL<T>*) ptr);
}

template <class T> Node<T>* TreeAVL<T>::remove(Node<T>* ptr) {
	return NULL;
}
