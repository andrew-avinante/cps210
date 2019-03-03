#ifndef ADJLIST_H
#define ADJLIST_H
#include <vector>
#include <iostream>

template <typename Weight, bool Undirected=true>
class AdjList
{
public:
    typedef unsigned int Vertex;
    struct VertexWeiht { Vertex v, Weight w; };
private:
    std::vector<vector<VertexWeight> > adj;
    unsigned int nEdges;
public:
    AdjList() { ; }
    AdjList(std::istream &is);
    void addVertex(Vertex u)
    {
        if(adj.size() <= u) { adj.resize(u + 1); }
    }
    void addEdge(Vertex u, Vertex v, Weight w)
    {
        addVertex(u < v ? v: u);
        // do some more stuff
        adj[u].push_back({v,w});
        if(Undirected)
        {
            adj[v].push_back({u, w});
        }
    }
    bool shortestPaths(Vertex start, std::vector<Vertex> &paths)
    {
        
    }
};

#endif