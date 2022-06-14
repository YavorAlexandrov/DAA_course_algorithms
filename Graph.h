#pragma once
#include<list>
#include<vector>
class Graph {
	std::vector<std::list<int>> vertices;
	int count;

public:
	Graph(int count) : count(count), vertices(count) {}

	int getCount() const{
		return count;
	}

	int addVertex() {
		vertices.push_back(std::list<int>());
		count++;
		return count - 1;
	}

	void addEdge(int start, int end) {
		vertices[start].push_back(end);
	}

	const std::list<int>& getAdj(int v) const {
		return vertices[v];
	}


	void print() const {
		for (int i = 0; i < count; i++) {
			std::cout << i << ": ";
			for (auto it = vertices[i].begin(); it != vertices[i].end(); ++it) {
				std::cout << (*it) << " ";
			}
			std::cout << std::endl;
		}

	}
};


