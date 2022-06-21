#pragma once
#include"WeightedGraph.h"
#include<vector>

std::vector<std::vector<int>> FloydWarshall(const WeightedGraph& g) {

	std::vector<std::vector<int>> distances;
	distances.resize(g.getCount(), std::vector<int>(g.getCount(), INT_MAX));

	for (int i = 0; i < g.getCount(); i++) {
		for (auto it = g.getAdj(i).begin(); it != g.getAdj(i).end(); ++it) {
			distances[i][(*it).first] = (*it).second;
		}
	}
	for (int i = 0; i < g.getCount(); i++) {
		distances[i][i] = 0;
	}

	for (int k = 0; k < g.getCount(); k++) {
		for (int i = 0; i < g.getCount(); i++) {
			for (int j = 0; j < g.getCount(); j++) {
				if ((distances[i][k] != INT_MAX && distances[k][j] != INT_MAX) && (distances[i][j] > distances[i][k] + distances[k][j])) {
					distances[i][j] = distances[i][k] + distances[k][j];
				}
			}
		}
	}
	return distances;
}

