#include "tree.hpp"

#include <iostream>

class probne {
public:
	int key;
};

int main() {
	Tree<int> a;
	a.insert(60);
	a.insert(80);
	a.insert(90);
	a.insert(70);
a.show();
	return 0;
}
