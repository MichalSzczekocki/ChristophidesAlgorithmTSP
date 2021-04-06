#include "main.h"
#include "Vertex.h"
#include "Graph.h"
#include <boost/random.hpp>
#include "boost/generator_iterator.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main()
{
	int v;
	std::cout << "Podaj ilosc wierzcholkow w grafie :" << std::endl;
	std::cin >> v;
	Graph* G = new Graph(v);
	G->DisplayWeightMatrix(v);
	G->DisplayVerticesData();
	G->DisplayList();
	return 0;
}
