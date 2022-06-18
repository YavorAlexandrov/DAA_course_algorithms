#pragma once
#include <vector>

class UnionFind
{
private:
	std::vector<size_t> parents;
	std::vector<size_t> sizes;

public:
	UnionFind(size_t n) : parents(n), sizes(n)// set of n elements (0..n-1)
	{
		for (size_t i = 0; i < n; i++)
		{
			parents[i] = i; // At the beginning each set consists of only one element which is also a parent to itself (and the leader of the set)
			sizes[i] = 1; // All sets are with one element
		}
	}

	bool Union(size_t n, size_t k) {
		size_t firstLeader = Find(n);
		size_t secondLeader = Find(k);

		if (firstLeader == secondLeader) // n and k are already in one set
			return false;

		if (sizes[firstLeader] < sizes[secondLeader])
			std::swap(firstLeader, secondLeader);

		// The set with leader "firstLeader" certainly has more elements than the other one
		parents[secondLeader] = firstLeader;
		sizes[firstLeader] += sizes[secondLeader];

		return true;
	} // O(log(n))
	size_t Find(size_t n) {
		if (parents[n] == n)
			return n;

		return Find(parents[n]);
	} // O(log(n))
};