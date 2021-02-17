#pragma once

#include <string>

/**
* @author Alicja Turowska
*
* funkcje porównujące dwie wartości
*/

/**
* porównuje dwie zmienne
*
* @param firstKey pierwsza zmienna
* @param secondKey druga zmienna
* @return 0 - dwie zmienne są równe; 1 - pierwsza zmienna jest większa od drugiej; -1 - pierwsza zmienna jest mniejsza od rugiej
*/
template <class T> int compare(T firstKey, T secondKey) {
	throw 0;
	return 0;
}

template <> int compare<int> (int firstKey, int secondKey) {
	if(firstKey==secondKey) return 0;
	else if(firstKey > secondKey) return 1;
	else return -1;
}

template <> int compare<std::string> (std::string firstKey, std::string secondKey) {
	if(firstKey==secondKey) return 0;
	else if(firstKey > secondKey) return 1;
	else return -1;
}
