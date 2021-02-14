@pragma once

/**
* @author Alicja Turowska
*/

#include tree.hpp

/**
* pojedynczy węzeł drzewa AVL
*/
template <class T> struct NodeAVL: public Node<T> {
	/**
	* współczynnik zrównoważenia drzewa
	*/
	int bf;
};

/**
* drzewo AVL o kluczu T
*/
template <class T> class TreeAVL {

public:
	/**
	* konstruktor tworzy puste drzewo
	*/
	TreeAVL();
	/**
	* niszczy drzewo AVL
	*/
	~TreeAVL();
	/**
	* wstawienie elementu
	*
	* @param key klucz do wstawienia
	* @return true - wstawiono element; flase - element o danym kluczu już istniał
	*/
	bool insert(T key);
	/**
	* usuwanie elementu
	*
	* @param key klucz elementu
	* @return zwraca usuwany element, jeżeli nie istniał - zwraca NULL
	*/
	T remove(T key);

private:
	/**
	* korzeń drzewa
	*/
	NodeAVL* root;
	/**
	* rotacja RR
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void RR(NodeAVL* ptr);
	/**
	* rotacja LL
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void LL(NodeAVL* ptr);
	/**
	* rotacja LR
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void LR(NodeAVL* ptr);
	/**
	* rotacja RL
	*
	* @param ptr wskaźnik na węzeł, który ma ulec rotacji
	*/
	void RL(NodeAVL* ptr);
	/**
	* znalezienie węzła o danym kluczu
	*
	* @param key wyszukiwany klucz
	* @return wskaźnik węzła, jeżeli nie istnieje - zwraca NULL
	*/
	NodeAVL* find(T key);
	/**
	* usunięcie węzła
	*
	* @param ptr wskaźnik węzła, który zostanie usunięty
	* @return wskaźnik usuwanego węzła
	*/
	NodeAVL* remove(NodeAVL* ptr);
};
