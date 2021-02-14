#pragma once

#include <string>

/**
* @author Alicja Turowska
*
* funkcje porównujące dwie wartości
*/

/**
* porównuje dwie liczby int
*
* @param firstKey pierwsza liczba
* @param secondKey druga liczba
* @return 0 - dwie liczby są równe; 1 - pierwsza liczba jest większa od drugiej; -1 - pierwsza liczba jest mniejsza od rugiej
*/
int compare(int firstKey, int secondKey);
/**
* porównuje dwa łańcuchy znaków
*
* @param firstKey pierwszy napis
* @param secondKey drugi napis
* @return 0 - dwa napisy są równe; 1 - pierwszy napis jest większy od drugiego; -1 - pierwsza liczba jest mniejsza od rugiej
*/
int compare(std::string firstKey, std::string secondKey);
