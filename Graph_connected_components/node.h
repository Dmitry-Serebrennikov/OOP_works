#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node {
	string name; 
public:
	set <Node*> neighbours;
	bool visited = false;
	void addNeighbour(Node* neighbour);
	void removeNeighbour(Node* neighbour);
	Node(const string& aname) : name(aname) {}
	const string& getName() const { return name; } 
	int getWeight(Node* a) const { return 1; }
	set<Node*>::iterator nb_begin() const { return neighbours.begin(); }
	set<Node*>::iterator nb_end() const { return neighbours.end(); }
	friend class Graph;
};
typedef set<Node*>::iterator node_iterator;

#endif