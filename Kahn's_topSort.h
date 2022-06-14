#pragma once
#include"Graph.h"
#include<queue>
#include<exception>
std::vector<int> Kahn(const Graph& g) {
	std::vector<int> inDegrees(g.getCount());
	for (int i = 0; i < g.getCount(); i++) {
		inDegrees[i] = 0;
	}

	for (int i = 0; i < g.getCount(); i++) {
		for (auto it = g.getAdj(i).begin(); it != g.getAdj(i).end(); ++it) {
			inDegrees[(*it)]++;
		}
	}

	std::vector<int> top;
	std::queue<int> q;

	for (int i = 0; i < g.getCount(); i++) {
		if (inDegrees[i] == 0) {
			q.push(i);
		}
	}

	int k = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		top.push_back(x);
		k++;
		for (auto it = g.getAdj(x).begin(); it != g.getAdj(x).end(); ++it) {
			inDegrees[(*it)]--;
			if (inDegrees[(*it)] == 0) {
				q.push(*it);
			}
		}
	}

	if (k < g.getCount()) {
		throw std::exception("Graph is cyclic");
	}
	else {
		return top;
	}
}


