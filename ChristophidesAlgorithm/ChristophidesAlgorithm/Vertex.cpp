#include "Vertex.h"
#include <string>

Vertex::Vertex(std::string _etykieta, int coordinate_x, int coordinate_y) {
	this->etykieta = _etykieta;
	this->x = coordinate_x;
	this->y = coordinate_y;
}
void Vertex::SetVertexNo(int n) {
	this->vertex_no = n;
}
int Vertex::GetPositionX() {
	return x;
}
int Vertex::GetPositionY() {
	return y;
}
bool Vertex::GetVisited() {
	return visited;
}
void Vertex::SetVisitedTrue() {
	this->visited = true;
}
bool Vertex::IsVisited() {
	if (this->visited == true) {
		return true;
	}
	else {
		return false;
	}
}
std::string Vertex::GetLabel() {
	return etykieta;
}
