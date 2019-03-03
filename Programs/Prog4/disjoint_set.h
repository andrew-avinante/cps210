#ifndef DisjointSet_H
#define DisjointSet_H
#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

template<typename T>
class disjoint_set
{
private:
	struct set_node
	{
		std::pair<T, int> parent;
		std::size_t rank;
	};
	std::map<T, set_node> nodes;
   	int size = 0;

public:
	disjoint_set() {}
	~disjoint_set() {}

	void insert(const T& elem)
	{
		if (nodes.find(elem) == nodes.end())
		{
			set_node new_node{ {elem, 1}, size_t{0u} };
			nodes[elem] = new_node;
			size++;
		}
	}

	std::pair<T, int> find(const T& node)
	{
		if (!(nodes[node].parent.first == node)) nodes[node].parent = find(nodes[node].parent.first);
		return nodes[node].parent;
	}

	bool merge(const T& a, const T& b)
	{
		T a_root = find(a).first;
		T b_root = find(b).first;
		if (a_root == b_root) return false;

		if (nodes[b].rank > nodes[a].rank)
        {
			nodes[a_root].parent.first = b_root;
            nodes[b_root].parent.second += nodes[a_root].parent.second;
        }
		else if (nodes[a].rank > nodes[b].rank)
        {
			nodes[b_root].parent.first = a_root;
            nodes[a_root].parent.second += nodes[b_root].parent.second;
        }
		else
		{
			nodes[b_root].parent.first = a_root;
			nodes[a_root].rank++;
            nodes[a_root].parent.second += nodes[b_root].parent.second;
		}
		size--;
		return true;
	}
	int GetSize()
	{
		return size;
	}
};

#endif