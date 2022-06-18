#pragma once
#include<list>
#include<vector>
#include<iostream>
class WeightedGraph {
	std::vector<std::list<std::pair<int, int>>> vertices;
	int count;

public:
	WeightedGraph(int count) : count(count), vertices(count) {}

	int getCount() const {
		return count;
	}

	int addVertex() {
		vertices.push_back(std::list<std::pair<int,int>>());
		count++;
		return count - 1;
	}

	void addEdge(int start, int end, int weight) {
		vertices[start].push_back(std::pair<int,int>(end, weight));
	}

	const std::list<std::pair<int,int>>& getAdj(int v) const {
		return vertices[v];
	}


	void print() const {
		for (int i = 0; i < count; i++) {
			std::cout << i << ": ";
			for (auto it = vertices[i].begin(); it != vertices[i].end(); ++it) {
				std::cout << "(" << (*it).first << "," << (*it).second << ") ";
			}
			std::cout << std::endl;
		}

	}
};