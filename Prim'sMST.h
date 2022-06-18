#pragma once
#include"WeightedGraph.h"

int minKey(const std::vector<int>& keys, const std::vector<bool>& mst) {
	int min = INT_MAX;
	int index = -1;

	for (int v = 0; v < keys.size(); v++) {
		if (mst[v] == false && keys[v] < min) {
			min = keys[v];
			index = v;
		}
	}
	return index;
}



std::vector<int> Prim(const WeightedGraph& g) {
	std::vector<int> parent(g.getCount());
	std::vector<int> keys(g.getCount());
	std::vector<bool> mst(g.getCount());
	
	for (int i = 0; i < g.getCount(); i++) {
		keys[i] = INT_MAX;
		mst[i] = 0;
	}

	keys[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < g.getCount() - 1; i++) {

		int u = minKey(keys, mst);

		mst[u] = true;

		for (auto it = g.getAdj(u).begin(); it != g.getAdj(u).end(); ++it) {
			if (mst[(*it).first] == false && (*it).second < keys[(*it).first]) {
				parent[(*it).first] = u;
				keys[(*it).first] = (*it).second;
			}
		}

	}
	return parent;
}

