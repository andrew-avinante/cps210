#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#include <vector>
#include <iostream>

template <typename Weight, bool Undirected=true>
class AdjMatrix {
public:
	typedef unsigned int Vertex;
	typedef std::vector<Vertex> v_vertex;
	typedef std::vector<Weight> v_weight;
	const Weight NoEdge;
private:
	std::vector< v_weight > adj;
	unsigned int nEdges;
public:
	AdjMatrix(Weight noEdge=0) : NoEdge(noEdge) { ; }
	//AdjMatrix(std::istream &is, Weight noEdge=0);
	
	unsigned int NumVertices() { return adj.size(); }
	unsigned int NumEdges() { return nEdges; }
	
	void addVertex(Vertex u) {
		// make sure that adj[u] is valid
		if (adj.size() <= u) { 
			for(auto &row : adj) {
				row.resize(u+1, NoEdge);
			}
			adj.resize(u+1, v_weight(u+1, NoEdge)); 
		}
	}
	
	void addEdge(Vertex u, Vertex v, Weight w) {
		addVertex(u < v ? v : u);
		
		adj[u][v] = w;
		if (Undirected) {
			adj[v][u] = w;
		}
	}
	
	friend std::ostream&operator <<(std::ostream &os, const AdjMatrix &mat) {
		for(auto &row : mat.adj) {
			for (auto w : row) {
				os << ' ' << w;
			}
			os << '\n';
		}
		return os;
	}
	
	Weight MWST_Prims(v_vertex &parent, Vertex start=0) {
		v_weight dist(adj[start]);
		for(int i = 0; i < dist.size(); i++)
		{
			dist[i] = -1;
		}
		std::vector<bool> processed(adj.size(), false);
		parent.clear();
		parent.resize(adj.size(), start);
		


		Weight totalCost=0;
		int nProcessed = 0;
		int curr;
		for(int i = 0; i < adj.size(); i++)
		{
			curr = i;
			if (processed[curr]) { continue; }
			processed[curr] = true; 
			++nProcessed;
			for (int j = 0; j < adj.size(); j++) {
				const Vertex v = j; // use a shorter/better? name
				//if (processed[v]) { continue; }
				if (NoEdge == dist[i] || (adj[i][j] < dist[i] && adj[i][j] != NoEdge)) {
					parent[v] = curr;
					dist[i] = adj[i][j];
					// next.push({dist[v], v});
				}
			}			
		}
		for(int i : dist)
		{
			std::cout << i << std::endl;
			totalCost += i;
		}
		return totalCost + 1;
	}
};

#endif