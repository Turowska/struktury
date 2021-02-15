#include "treeAVL.hpp"

template <class T> NodeAVL<T>::NodeAVL(T key, NodeAVL<T>* parent): Node<T>(key, parent) {
	bf = 0;
}

template <class T> bool TreeAVL<T>::insert(T key) {
	return true;
}

template <class T> void TreeAVL<T>::RR(NodeAVL<T>* ptr) {

}

template <class T> void TreeAVL<T>::LL(NodeAVL<T>* ptr) {

}

template <class T> void TreeAVL<T>::LR(NodeAVL<T>* ptr) {

}

template <class T> void TreeAVL<T>::RL(NodeAVL<T>* ptr) {

}

template <class T> Node<T>* TreeAVL<T>::remove(Node<T>* ptr) {
	return NULL;
}
