#pragma once

/**
* @author Alicja Turowska
*/

#include "tree.hpp"

/**
* pojedynczy węzeł drzewa AVL
*/
template <class T> struct NodeAVL: public Node<T> {
	/**
	* współczynnik zrównoważenia drzewa
	*/
	int bf;
	/**
	* tworzy nowy węzeł
	*
	* @param key klucz węzła
	* @param parent wskaźnik na rodzica
	*/
	NodeAVL(T key, NodeAVL<T>* parent);
};

/**
* drzewo AVL o kluczu T
*/
template <class T> class TreeAVL: public Tree<T> {

public:
	/**
	* wstawienie elementu
	*
	* @param key klucz do wstawienia
	*/
	virtual bool insert(T key);

private:
	/**
	* rotacja RR
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void RR(NodeAVL<T>* ptr);
	/**
	* rotacja LL
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void LL(NodeAVL<T>* ptr);
	/**
	* rotacja LR
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void LR(NodeAVL<T>* ptr);
	/**
	* rotacja RL
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void RL(NodeAVL<T>* ptr);
	
	/**
	* usunięcie węzła
	*
	* @param ptr wskaźnik węzła, który zostanie usunięty
	* @return wskaźnik usuwanego węzła
	*/
	virtual Node<T>* remove(Node<T>* ptr);
};

#include "treeAVL.tpp"
