#pragma once
#include<algorithm>
#include"UnionFind.h"
#include"WeightedGraph.h"
struct Edge {
	int start;
	int end;
	int weight;

	Edge(int s, int e, int w) : start(s), end(e), weight(w) {}
};

void addEdges(const WeightedGraph& g, std::vector<Edge>& edges) {
	std::vector<bool> visited(g.getCount());
	for (int i = 0; i < g.getCount(); i++) {
		for (auto it = g.getAdj(i).begin(); it != g.getAdj(i).end(); ++it) {
			if (!visited[(*it).first])
				edges.push_back(Edge(i, (*it).first, (*it).second));
		}
		visited[i] = true;
	}
}

bool cmp(const Edge& e1, const Edge& e2) {
	return e1.weight < e2.weight;
}

std::vector<Edge> Kruskal(const WeightedGraph& g) {
	UnionFind uf(g.getCount());
	std::vector<Edge> edges;
	addEdges(g, edges);

	std::sort(edges.begin(), edges.end(), cmp);
	
	int addedEdges = 0;
	std::vector<Edge> mst;
	for (int i = 0; addedEdges < g.getCount() - 1; i++) {
		Edge current = edges[i];
		int currStart = current.start;
		int currEnd = current.end;
		int currWeight = current.weight;

		if (!uf.Union(currStart, currEnd)) {
			continue;
		}
		mst.push_back(edges[i]);
		addedEdges++;
	}
		return mst;
}
