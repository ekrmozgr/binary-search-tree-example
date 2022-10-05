#include <iostream>
#include "AgacIslem.hpp"
#include "Node.hpp"
using namespace std;

int main()
{
	AgacIslem *agacIslem = new AgacIslem();
	agacIslem->islemler();
	delete agacIslem;
	return 0;
}
