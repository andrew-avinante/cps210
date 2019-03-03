#ifndef ADJLIST_H
#define ADJLIST_H
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

template <typename Weight, bool Undirected=true>
class AdjList {
public:
	typedef unsigned int Vertex;
	typedef std::pair<Weight, Vertex> WeightVertex;
	typedef std::vector<WeightVertex> v_wv;
	typedef std::vector<Vertex> v_vertex;
	typedef std::vector<Weight> v_weight;
private:
	std::vector< v_wv > adj;
	unsigned int nEdges;
public:
	AdjList() { ; }
	AdjList(std::istream &is);
	
	unsigned int NumVertices() { return adj.size(); }
	unsigned int NumEdges() { return nEdges; }
	
	void addVertex(Vertex u) {
		// make sure that adj[u] is valid
		if (adj.size() <= u) { adj.resize(u+1); }
	}
	void addEdge(Vertex u, Vertex v, Weight w) {
		addVertex(u < v ? v : u);

		++nEdges;
		adj[u].push_back({w, v});
		if (Undirected) {
			adj[v].push_back({w, u});
		}
	}
	
	/*---------------------------------------------------------------------- *
	    Method: shortestPaths
	    Parameters:
	      start: Vertex, the location from which the construction of paths begins
		  parent: v_vertex, the parent (of each vertex) in the search tree which
		      is rooted at start. parent[start] = start.
		  dist: v_weight, the distance from start to each vertex
		  NoEdge: Weight, a value to use to indicate the absence of a connection
	    Returns: bool; whether all vertices have been found, is connected?
		
		This method constructs a shortest path tree rooted at start and connecting
		all vertices which are reachable from start. For a vertex v, its distance,
		in the tree/graph, to start is stored in dist[v], while parent[v] stores
		the parent of v in the shortest path tree.
	 *---------------------------------------------------------------------- */
	bool shortestPaths(Vertex start, v_vertex &parent, v_weight &dist, const Weight NoEdge=-1) {
		parent.clear(); parent.resize(adj.size(), start);
		dist.clear(); dist.resize(adj.size(), NoEdge);
		std::vector<bool> processed(adj.size(), false);
		std::priority_queue<WeightVertex, v_wv, std::greater<WeightVertex> > next;
		
		dist[start] = 0;
		next.push({0, start});
		unsigned int nProcessed=0;
		while (!next.empty() && nProcessed < adj.size()) {
			auto top_pr = next.top();
			next.pop();
			Vertex curr = top_pr.second;
			Weight curr_dist = top_pr.first;
			
			if (processed[curr]) { continue; }
			processed[curr] = true; 
			++nProcessed;
			for (auto pr : adj[curr]) {
				const Vertex v = pr.second; // use a shorter/better? name
				if (processed[v]) { continue; }
				if (NoEdge == dist[v] || curr_dist+pr.first < dist[v]) {
					parent[v] = curr;
					dist[v] = curr_dist+pr.first;
					next.push({dist[v], v});
				}
			}				
		}
		return (nProcessed == adj.size());
	}
	
	bool prims(Vertex start, v_vertex &parent, v_weight &dist, const Weight NoEdge=-1) {
		parent.clear(); parent.resize(adj.size(), start);
		dist.clear(); dist.resize(adj.size(), NoEdge);
		std::vector<bool> processed(adj.size(), false);
		std::priority_queue<WeightVertex, v_wv, std::greater<WeightVertex> > next;
		
		dist[start] = 0;
		next.push({0, start});
		unsigned int nProcessed=0;
		while (!next.empty() && nProcessed < adj.size()) {
			auto top_pr = next.top();
			next.pop();
			Vertex curr = top_pr.second;
			Weight curr_dist = top_pr.first;
			
			if (processed[curr]) { continue; }
			processed[curr] = true; 
			++nProcessed;
			for (auto pr : adj[curr]) {
				const Vertex v = pr.second; // use a shorter/better? name
				if (processed[v]) { continue; }
				if (NoEdge == dist[v] || pr.first < dist[v]) {
					parent[v] = curr;
					dist[v] = pr.first;
					next.push({dist[v], v});
				}
			}				
		}
		return (nProcessed == adj.size());
	}
};

#endif