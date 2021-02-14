#include "compare.hpp"

int compare(int firstKey, int secondKey) {
	if(firstKey==secondKey) return 0;
	else if(firstKey > secondKey) return 1;
	else return -1;
}

int compare(std::string firstKey, std::string secondKey) {
	if(firstKey==secondKey) return 0;
	else if(firstKey > secondKey) return 1;
	else return -1;
}
