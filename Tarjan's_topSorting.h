#pragma once
#include"Graph.h"

//0 - white, 1 - gray, 2 - black
void TarjanRec(const Graph& g, int v, std::vector<short>& colors, std::vector<int>& top, int& l, int& time, std::vector<int>& finalized) {
	colors[v] = 1;
	
	for (auto it = g.getAdj(v).begin(); it != g.getAdj(v).end(); ++it) {
		if (colors[*it] == 0) {
			TarjanRec(g, *it, colors, top, l, time, finalized);
		}
	}
	colors[v] = 2;

	time++;
	finalized[v] = time;
	
	top[l] = v;
	l--;
}

std::vector<int> Tarjan(const Graph& g) {
	std::vector<short> colors(g.getCount());
	std::vector<int> top(g.getCount());
	std::vector<int> finalized(g.getCount());

	int l = g.getCount() - 1;
	int time = 0;

	for (int i = 0; i < g.getCount(); i++) {
		colors[i] = 0;
	}
	for (int i = 0; i < g.getCount(); i++) {
		if (colors[i] == 0) {
			TarjanRec(g, i, colors, top, l, time, finalized);
		}
	}
	return top;
}

