#include "treeAVL.hpp"
#include "treeSplay.hpp"

#include <iostream>

class probne {
public:
	int key;
};

int main() {
	TreeSplay<int> a;
	a.insert(2);
	a.insert(1);
	a.insert(4);
	a.insert(3);
	a.show();
	return 0;
}
