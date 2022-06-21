#pragma once
#include"WeightedGraph.h"
#include<vector>

std::vector<int> BellmanFord(const WeightedGraph& g, int start) {
	std::vector<int> distances;
	distances.resize(g.getCount(), INT_MAX);
	distances[start] = 0;

	bool change = true;
	for (int l = 0; l < g.getCount(); l++) {
		if (!change)
			break;
		change = false;

		for (int i = 0; i < g.getCount(); i++) {
			if (distances[i] == INT_MAX)
				continue;

			for (auto it = g.getAdj(i).begin(); it != g.getAdj(i).end(); ++it) {

				if (distances[(*it).first] > distances[i] + (*it).second) {
					distances[(*it).first] = distances[i] + (*it).second;
					change = true;
				}

			}
		}
	}
	for (int i = 0; i < g.getCount(); i++) {
		for (auto it = g.getAdj(i).begin(); it != g.getAdj(i).end(); ++it) {
			if (distances[i] != INT_MAX && (distances[(*it).first] > distances[i] + (*it).second))
				throw "Negative cycle detected";
		}
	}
	return distances;
}
