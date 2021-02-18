#pragma once

/**
* @author Alicja Turowska
*/

#include "compare.hpp"

/**
* pojedynczy węzeł drzewa
*/
template <class T> struct Node {
	/**
	* wskaźnik na rodzica
	*/
	Node<T>* parent;
	/**
	* wskaźnik na lewe (mniejsze) dziecko
	*/
	Node<T>* leftChild;
	/**
	* wskaźnik na prawe (większe) dziecko
	*/
	Node<T>* rightChild;
	/**
	* klucz
	*/
	T key;
	/**
	* tworzy nowy węzeł
	*
	* @param key klucz węzła
	* @param parent wskaźnik na rodzica
	*/
	Node(T key, Node<T>* parent);
	/**
	* tworzy nowy węzeł
	*
	* @param key klucz węzła
	* @param leftChild wskaźnik na lewe dziecko
	* @param rightChild wskaźnik na prawe dziecko
	*/
	Node(T key, Node<T>* leftChild, Node<T>* rightChild);
};

/**
* drzewo BTS
*/
template <class T> class Tree {

public:
	/**
	* konstruktor tworzy puste drzewo
	*/
	Tree();
	/**
	* niszczy drzewo
	*/
	~Tree();
	/**
	* wstawianie elementu
	*
	* @param key klucz do wstawienia
	* @return true - wstawiono element; false - element już istniał
	*/
	virtual bool insert(T key);
	/**
	* usuwa podany element
	*
	* @param key klucz elementu do usunięia
	* @return true - usunięto element; false - nie ma takiego elementu
	*/
	virtual bool remove(T &key);
	/**
	* wyszukanie elementu
	*
	* @param key klucz elementu
	* @return true - znaleziono element i umieszczono w podanym argumencie; false - nie ma elementu
	*/
	virtual bool find(T &key);
	/**
	* wyświetlanie drzewa
	*/
	void show();

protected:
	/**
	* korzeń drzewa
	*/
	Node<T>* root_;
	/**
	* wyszukanie węzła o danym kluczu
	*
	* @param key wyszukiwany klucz
	* @return wyszukany węzeł, jeżeli nie istnieje - NULL
	*/
	virtual Node<T>* findNode(T &key);
	/**
	* usunięcie podanego węzła
	*
	* @param węzeł do usunięcia
	* @return usuwany węzeł
	*/
	virtual Node<T>* remove(Node<T>* ptr);

private:
	/**
	* funkcja pomocnicza do niszczenia drzewa
	* usuwa poddrzewo
	*
	* @param root korzeń poddrzewa
	*/
	void removeTree(Node<T>* root);
	/**
	* znajduje poprzednik podanego węzła
	*
	* @param ptr wskaźnik węzła dla którgo szukany jest poprzednik
	* @return poprzednik węzła
	*/
	Node<T>* pred(Node<T>* ptr);
	/**
	* znajduje następnik podanego węzła
	*
	* @param ptr wskaźnik węzła dla którego szukamy następnika
	* @return następnik węzła
	*/
	Node<T>* succ(Node<T>* ptr);
	/**
	* wyświetlanie drzewa, funkcja pomocnicza
	*
	* @param ptr wyświetlany węzeł
	* @param sp napis pomocniczy
	* @param sn węzeł określający dziecko
	*/
	void show(Node<T>* ptr, std::string sp, std::string sn);
};

#include "tree.tpp"
