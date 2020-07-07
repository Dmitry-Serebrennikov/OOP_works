#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include "node.h"

using namespace std;

class Graph {
public:
	set<Node*> nodes;
	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);

	node_iterator begin() { return nodes.begin(); }
	node_iterator end() { return nodes.end(); }
};

class BFS {
	const Graph& graph;
public:
	BFS(const Graph& agraph) : graph(agraph) {}
	bool connected(Node* begin, Node* end);
};

class DFS {
	const Graph& graph;
	set<Node*> visited;
	bool connected(Node* begin, Node* end, int depth);
public:
	DFS(const Graph& agraph) : graph(agraph) {}
	bool connected(Node* begin, Node* end);
	static bool connected(Node* begin);
};

struct MarkedNode {
	Node* node; int mark;
	Node* prev;
	MarkedNode(Node* anode = 0, int amark = 0, Node * aprev = 0) :
		node(anode), mark(amark), prev(aprev) {};
};

class PriorityQueue {
	vector<MarkedNode> nodes;
public:
	MarkedNode pop();
	void push(Node* node, int mark, Node* prev);
	bool empty() const { return nodes.empty(); }
};

struct Way {
	vector<Node*> nodes;
	int length;
	Way() : length(-1) {}
};
class Dijkstra {
	const Graph& graph;
public:
	Dijkstra(const Graph& agraph) : graph(agraph) {}
	Way shortestWay(Node* begin, Node* end);
};

#endif