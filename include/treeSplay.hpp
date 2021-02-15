#pragma once

/**
* @author Alicja Turowska
*/

#include "tree.hpp"

/**
* drzewo Splay o kluczu T
*/
template <class T> class TreeSplay: public Tree<T> {

public:
	/**
	* wstawienie elementu
	*
	* @param key klucz do wstawienia
	*/
	virtual bool insert(T key);
	/**
	* wyszukanie elementu
	*
	* @param key klucz elementu
	* @return wyszukany element
	*/
	virtual T* find(T key);
	/**
	* usuwa podany element
	*
	* @param key klucz elementu do usunięia
	* @return usunięty element
	*/
	virtual T* remove(T key);

private:
	/**
	* rotacja R
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void R(Node<T>* ptr);
	/**
	* rotacja L
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void L(Node<T>* ptr);
	/**
	* operacja splay
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void splay(Node<T>* ptr);
	/**
	* usunięcie węzła
	*
	* @param ptr wskaźnik węzła, który zostanie usunięty
	* @return wskaźnik usuwanego węzła
	*/
	virtual Node<T>* remove(Node<T>* ptr);
	/**
	* wyszukanie węzła o danym kluczu
	*
	* @param key wyszukiwany klucz
	* @return wyszukany węzeł, jeżeli nie istnieje - najbliższy wyszukiwanemu
	*/
	virtual Node<T>* findNode(T key);
};

#include "treeSplay.tpp"
