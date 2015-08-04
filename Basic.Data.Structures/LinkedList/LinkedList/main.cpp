#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.remove(0);
	int p = l.find(2);
	std::cout << l[p].Value << '\n';
	std::cout << l[0].Value << '\n';
	std::cout << l[1].Value << '\n';
		
	return 0;
}