#pragma once
#include<vector>
#include<queue>
#include"WeightedGraph.h"

std::vector<int> Dijkstra(const WeightedGraph& g, int start) {
	std::vector<int> distances;
	distances.resize(g.getCount(), INT_MAX);

	struct VertexDistancePair {
		int vertex;
		int distanceFromStart;

		bool operator <(const VertexDistancePair& other) const{
			return distanceFromStart > other.distanceFromStart;
		}
	};

	std::priority_queue<VertexDistancePair> q;
	distances[start] = 0;
	q.push({ start,0 });

	while (!q.empty()) {
		VertexDistancePair current = q.top();
		q.pop();

		int currVertex = current.vertex;
		int currDist = current.distanceFromStart;

		for (auto it = g.getAdj(currVertex).begin(); it != g.getAdj(currVertex).end(); ++it) {
			int currSucc = (*it).first;
			int distFromCurr = (*it).second;

			if (distances[currSucc] > currDist + distFromCurr) {
				distances[currSucc] = currDist + distFromCurr;
				q.push({ currSucc, distances[currSucc] });
			}
		}

	}
	return distances;
}

