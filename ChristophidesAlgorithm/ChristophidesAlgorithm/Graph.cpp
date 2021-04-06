#include "Graph.h"
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <boost/random.hpp>
#include "boost/generator_iterator.hpp"
#include <cmath>
#include <climits>
#include <limits>

Graph::Graph(int num_of_vertices) {
	typedef boost::mt19937 RNGType; ///Mersenne twister generator
	RNGType rng(time(0));

	boost::uniform_int<> zero_to_thousand(0, 1000);
	boost::variate_generator< RNGType, boost::uniform_int<> > point(rng, zero_to_thousand);
	/*-----------------------------------------------------------------------------------*/
	for (int i = 0; i < num_of_vertices; ++i) {
		std::string vertex_label;
		std::cout << "Podaj nazwe wierzcholka " << std::endl;
		std::cin >> vertex_label;
		Vertex* V = new Vertex(vertex_label, point(), point());
		V->SetVertexNo(i);
		vertices_list.push_back(*V);

		SetGraphEdgesWeight();
		MatrixToEdgeList();
	}
	queue = vertices_list; //przepisanie wszystkich elementow z listy wierzcholkow do kolejki (z ktorej i tak pokoleji beda wszystkie usuwane w algorytmie MST)
}
float Graph::SetEdgeWeight(Vertex* comparing, Vertex* being_compared) { //Liczenie euklidesowej odleglosci pomiedzy punktami
	int absolute_x = (comparing->GetPositionX() - being_compared->GetPositionX());
	int absolute_y = (comparing->GetPositionY() - being_compared->GetPositionY());
	float edge_weight = (float)(sqrt(pow(absolute_x, 2) + pow(absolute_y, 2)));
	return edge_weight;
}
void Graph::SetGraphEdgesWeight() {
	int i = 0;
	for (std::vector<Vertex>::iterator it = vertices_list.begin(); it != vertices_list.end(); ++it) {
		Vertex* pointer = &*it;
		int n = 0;
		for (std::vector<Vertex>::iterator it2 = vertices_list.begin(); it2 != vertices_list.end(); ++it2) {
			Vertex* pointee = &*it2;
			//cost_matrix[i][n] = SetEdgeWeight(pointer, pointee);
			if (pointee->IsVisited() == true) {
				cost_matrix[i][n] = cost_matrix[n][i];
			}
			else if (it == it2) {
				cost_matrix[i][n] = 0;
			}
			else {
				pointer->SetVisitedTrue();
				cost_matrix[i][n] = SetEdgeWeight(pointer, pointee);
			}
			++n;
		}
		++i;
	}
}
void Graph::DisplayWeightMatrix(int num_of_vertices) {
	for (int i = 0; i < num_of_vertices; ++i) {
		for (int j = 0; j < num_of_vertices; ++j) {
			std::cout << "*" << " " << cost_matrix[i][j] << " ";
		}
		std::cout << "*" << std::endl;
	}
}
void Graph::DisplayVerticesData() {
	int i = 1;
	for (std::vector<Vertex>::iterator it = vertices_list.begin(); it != vertices_list.end(); ++it) {
		std::cout << "Wierzcholek numer: " << i << " " << "x:" << it->GetPositionX() << " " << "y:" << it->GetPositionY() << std::endl;
		++i;
	}
}
void Graph::MatrixToEdgeList() {
	int i = 0;
	for (std::vector<Vertex>::iterator it = vertices_list.begin(); it != vertices_list.end(); ++it) {
		int n = 0;
		for (std::vector<Vertex>::iterator it2 = vertices_list.begin(); it2 != vertices_list.end(); ++it2) {
			//std::vector<Vertex>::iterator it3 = ++it2;

			if (cost_matrix[i][n] == 0) {
				++n;
				break;
			}
			else {
				struct Edge* e = new struct Edge;
				e->vertex1 = it->GetLabel();
				e->vertex2 = it2->GetLabel();
				e->weight = cost_matrix[i][n];
				edge_list.push_back(*e);
				++n;
			}
		}
		++i;
	}
}
void Graph::DisplayList() {
	for (std::vector<Edge>::iterator it = edge_list.begin(); it != edge_list.end(); ++it) {
		std::cout << "Wierzcholek poczatkowy: " << it->vertex1 << " " << "Koncowy: " << it->vertex2 << " " << "Waga: " << it->weight << "\n";
	}
}
void Graph::Christofides(Graph& g) {
	for (std::vector<Vertex>::iterator it = vertices_list.begin(); it != vertices_list.end(); ++it) { //iteruje wzdluz wektora z wierzcholkami i
		Vertex* pointer = &*it;
		g.KEY.insert(std::pair<Vertex, float>(*pointer, std::numeric_limits<float>::max())); //zapiseuje aktualnie wskazywany przez iterator wierzcholek jako klucz mapy
		//KEY.emplace(*pointer, std::numeric_limits<float>::max());

		//while (!queue.empty() {

		//}
	}


	/*
	for (auto v : g.vertices_list) {

		//KEY.insert(*v_pointer, std::numeric_limits<float>::max());
		//KEY.insert(std::make_pair(v, std::numeric_limits<float>::max()));
		//KEY[v] = std::numeric_limits<float>::max();
	}
	*/
}