#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include "graph.h"
#include "node.h"

using namespace std;

void Graph::addNode(Node* node)
{
	this->nodes.insert(node);
}
void Graph::removeNode(Node* node) {  
	nodes.erase(node);
	for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
		(*it)->removeNeighbour(node);
	}
}
void Node::addNeighbour(Node* neighbour) {
	this->neighbours.insert(neighbour);
}

void Node::removeNeighbour(Node* neighbour) {
	this->neighbours.erase(neighbour);
}
void Graph::addEdge(Node* begin, Node* end) {   
	if (nodes.find(begin) == nodes.end())
		return;
	if (nodes.find(end) == nodes.end())
		return;
	begin->addNeighbour(end);
	end->addNeighbour(begin);
}
void Graph::removeEdge(Node* begin, Node* end) {
	this->nodes.erase(begin);
	this->nodes.erase(end);
	for (node_iterator it = this->nodes.begin(); it != this->nodes.end(); it++) {
		(*it)->removeNeighbour(begin);
		(*it)->removeNeighbour(end);
	}
}

bool BFS::connected(Node* begin, Node* end) {
	queue<Node*> nodes; nodes.push(begin);
	set<Node*> visited;

	while (!nodes.empty()) {
		Node* next = nodes.front(); nodes.pop();
		if (end == next) return true;
		visited.insert(next);
		for (node_iterator it = next->nb_begin(); it != next->nb_end(); it++) { //
			if (visited.find(*it) == visited.end())
				nodes.push(*it);
		}
	}
	return false;
}


bool DFS::connected(Node* begin) {
	begin->visited = true;
	for (node_iterator it = begin->nb_begin(); it != begin->nb_end(); it++) {
		if (!(*it)->visited) {
			DFS::connected(*it);
		}
	}
	return false;
}


MarkedNode PriorityQueue::pop() {
	MarkedNode mn = nodes.back();
	nodes.pop_back();
	return mn;
}
void PriorityQueue::push(Node* node, int mark, Node* prev) {
	vector<MarkedNode>::iterator it = nodes.begin();
	MarkedNode mn(node, mark, prev);
	while (it != nodes.end() && mark < it->mark) it++;
	if (it == nodes.end()) nodes.push_back(mn);
	else nodes.insert(it, mn);
}

static Way unroll(map<Node*, MarkedNode> visited, Node* begin, Node* curr) {
	Way way;
	way.length = visited[curr].mark;
	while (curr != begin) {
		way.nodes.push_back(curr);
		curr = visited[curr].prev;
	}
	way.nodes.push_back(begin);
	return way;
}

Way Dijkstra::shortestWay(Node* begin, Node* end) {
	PriorityQueue nodes; nodes.push(begin, 0, 0);
	map<Node*, MarkedNode> visited;
	while (!nodes.empty()) {
		MarkedNode next = nodes.pop();
		visited[next.node] = next;
		if (end == next.node) return unroll(visited, begin, end);
		for (node_iterator it = next.node->nb_begin(); it != next.node->nb_end(); it++) {
			int weight = (*it)->getWeight(next.node) + next.mark;
			if (visited.find(*it) == visited.end())
				nodes.push(*it, weight, next.node);
		}

	}
	return Way();
}
