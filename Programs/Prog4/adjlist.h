#ifndef ADJLIST_H
#define ADJLIST_H
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <queue>
#include "disjoint_set.h"
#include <list>

template <typename Weight, bool Undirected=true>
class AdjList {
public:
	typedef unsigned int Vertex;
	typedef std::pair<Weight, Vertex> WeightVertex;
	typedef std::vector<WeightVertex> v_wv;
	typedef std::vector<Vertex> v_vertex;
	typedef std::vector<Weight> v_weight;
private:
	struct edges
	{
		Vertex v1, v2;
		Weight w;
		bool operator <( const edges &a ) const
		{
		return ( w < a.w );
		}
	};
	struct cmp
	{ 
		bool operator()(edges const& a, edges const& b) 
		{ 
			if(b.w == a.w)
			{
				if(b.v1 == a.v1)
				{
					return b.v2 < a.v2;
				}
				else
				{
					return b.v1 < a.v1;
				}
			}
			return b.w <= a.w; 
		}
    };
public:
	typedef std::vector<edges> edge;
private:
	std::vector< v_wv > adj;
	unsigned int nEdges;
	std::priority_queue<edges, edge, cmp > next;
public:
	AdjList() { ; }
	AdjList(std::istream &is);
	unsigned int NumVertices() { return adj.size(); }
	unsigned int NumEdges() { return nEdges; }
	std::list<std::pair<Vertex,Vertex>> order;
	void addVertex(Vertex u) {
		// make sure that adj[u] is valid
		if (adj.size() <= u) { adj.resize(u+1); }
	}
	void addEdge(Vertex u, Vertex v, Weight w) {
		addVertex(u < v ? v : u);
		next.push({u,v,w});
		++nEdges;
		adj[u].push_back({w, v});
		if (Undirected) {
			adj[v].push_back({w, u});
		}
	}

	void printPQ()
	{
		for (auto t : adj)
		{
		std::cout << next.top().first << " " << next.top().second << std::endl;
		next.pop();
		}
	}

	int kruskals() {
		disjoint_set<unsigned int> sets;
		
		int weight = 0;
		edges e;
		while (!next.empty()) 
		{
			e = next.top();
			next.pop();
			sets.insert(e.v1);
			sets.insert(e.v2);
			if(sets.merge(e.v1, e.v2))
			{
				weight += e.w;
				order.push_back({e.v1, e.v2});
				std::cout << e.v1 << ' ' << e.v2 << ' ' << e.w << std::endl;
			}
		}
		return (sets.GetSize() == 1) ? weight : -1;
	}
	 
	void processOutput()
	{
		int w = kruskals();
		if(w != -1)
		{
			std::cout << "The weight of the MWST is " << w << std::endl;
		}
		else
		{
			std::cout << "Graph is disconnected" << std::endl;
		}
	}
};

#endif
