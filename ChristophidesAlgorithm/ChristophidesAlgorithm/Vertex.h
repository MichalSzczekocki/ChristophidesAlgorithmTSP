#pragma once
#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <boost/functional/hash.hpp>

class Vertex{
private:
	std::string etykieta;
	int x;
	int y;
	int vertex_no;
	bool visited;
public:
	Vertex(std::string _etykieta, int coordinate_x, int coordinate_y);
	void SetVertexNo(int n);
	int GetPositionX();
	int GetPositionY();
	bool GetVisited();
	void SetVisitedTrue();
	bool IsVisited();
	std::string GetLabel();

	friend std::size_t hash_value(Vertex const& v) { //Vertex const& v
		std::size_t seed = 0;
		boost::hash_combine(seed, v.x);
		boost::hash_combine(seed, v.y);

		return seed;
	}
	bool operator==(Vertex const& other) const {
		return std::tie(x, y) == std::tie(other.x, other.y);
	}
};
#endif // VERTEX_H
