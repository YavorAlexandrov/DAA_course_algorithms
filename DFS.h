#pragma once
#include "Graph.h"
#include<iostream>
//0 - white, 1 - gray, 2 - black
void DFSrec(const Graph& g, std::vector<int>& traversedTree , std::vector<short>& colors, int v, int& time, std::vector<int>& discovered, std::vector<int>& finalized) {
	colors[v] = 1;
	time++;
	discovered[v] = time;
	for (auto it = g.getAdj(v).begin(); it != g.getAdj(v).end(); ++it) {
		if (colors[*it] == 0) {
			traversedTree[*it] = v;
			DFSrec(g, traversedTree, colors, *it, time, discovered, finalized);
		}
	}
	colors[v] = 2;
	time++;
	finalized[v] = time;
}


void DFS(const Graph& g) {
	int time = 0;
	std::vector<short> colors(g.getCount());
	std::vector<int> traversedTree(g.getCount());
	std::vector<int> discovered(g.getCount());
	std::vector<int> finalized(g.getCount());
	
	for (int i = 0; i < g.getCount(); i++) {
		colors[i] = 0;
		traversedTree[i] = -1;
	}

	for (int i = 0; i < g.getCount(); i++) {
		if (colors[i] == 0) {
			DFSrec(g, traversedTree, colors, i, time, discovered, finalized);
		}
	}

	std::cout << "traversal tree" << std::endl;
	for (int i = 0; i < g.getCount(); i++)
		std::cout << traversedTree[i] << " ";

	std::cout << std::endl << "discovered" << std::endl;
	for (int i = 0; i < g.getCount(); i++)
		std::cout << discovered[i] << " ";

	std::cout << std::endl << "finalized" << std::endl;
	for (int i = 0; i < g.getCount(); i++)
		std::cout << finalized[i] << " ";
}