#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <map>
#include "graph.h"
#include "node.h"

using namespace std;
int main()
{
	Graph* graph = new Graph;
	map<string, Node*> m;
	ifstream in("D:\TestGraph.txt");
	string line;
	getline(in, line);
	while (getline(in, line)) {
		string source, target;
		in >> source >> target;
		if (m.find(source) == m.end()) {
			Node* numberSource = new Node(source);
			m.insert(pair<string, Node*>(source, numberSource));

		}
		Node* numberTarget = new Node(target);
		if (m.find(target) == m.end()) {
			m.insert(pair<string, Node*>(target, numberTarget));

		}
		graph->addNode(m[source]);
		graph->addNode(m[target]);
		graph->addEdge(m[source], m[target]);
	}
	int n = 0;

	for (node_iterator it = graph->begin(); it != graph->end(); it++) {
		if (!((*it)->visited)) {
			DFS::connected(*it);
			n++;
		}
	}
	cout << n;
}

