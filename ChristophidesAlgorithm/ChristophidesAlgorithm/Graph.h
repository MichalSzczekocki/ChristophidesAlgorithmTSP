#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include <vector>
#include <unordered_map>
#include <limits>
#include <boost/functional/hash.hpp>
#include <boost/unordered_set.hpp>
#include <boost\unordered_map.hpp>

class Graph{
private:
	const int VERTICES_MAX = 120;
	const int VERTICES_MIN = 5;

	std::vector<Vertex> vertices_list;
	float cost_matrix[120][120];

	struct Edge { std::string vertex1; std::string vertex2; float weight; };
	std::vector<Edge> edge_list;

	boost::unordered_map<Vertex, float> KEY;
	//boost::unordered_set<Vertex, float> KEY; /*boostowa tablica z haszowaniem jest lepsza*/
	//std::unordered_map<Vertex, float> KEY; /*custom hash functions(helped a lot!): stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key*/

	std::vector<Vertex> queue;

public:
	Graph(int num_of_vertices);
	float SetEdgeWeight(Vertex* comparing, Vertex* being_compared);
	void SetGraphEdgesWeight();
	void DisplayWeightMatrix(int num_of_vertices);
	void DisplayVerticesData();
	void MatrixToEdgeList();
	void DisplayList();

	void Christofides(Graph& g);

	//std::vector<std::pair<Vertex, Edge> > adjacent(Vertex) {};
};
#endif // GRAPH_H