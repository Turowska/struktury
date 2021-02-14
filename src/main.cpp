#include "tree.hpp"

#include <iostream>

class probne {
public:
	int key;
};

int main() {
	Tree<int> a;
	a.insert(5);
	a.insert(6);
std::cout<<a.find(6)<<std::endl;
std::cout<<a.remove(5)<<std::endl;
std::cout<<a.remove(6)<<std::endl;
	return 0;
}
