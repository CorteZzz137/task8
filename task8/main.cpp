#include <iostream>
#include <list>
#include <vector>
#include "poly.hpp"
using namespace std;


int main()
{
	Polynomial A({ make_pair(1, 1), make_pair(0, -4) });
	A.write();
	Polynomial B({ make_pair(1, -4), make_pair(0, 3) });
	B.write();
	A *= B;
	A.write();
	A *= (Polynomial)4;
	A.write();
	return 0;
}