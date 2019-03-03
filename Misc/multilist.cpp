#include <vector>

template <typename Weight>
class MultiList
{
    public:
        typedef unsigned int Vertex;
        typedef unsigned int Index;
        struct Edge3
        {
            Vertex u, v;
            Weight w;
        };
        struct Node 
        {
            Edge3 e;
            Index next_u, next_v;
            Index next(Vertex x)
            {
                return (u == x ? next_u : next_v);
            }
        };
        const Index NullIndex = 0;
    private:
        std::vector<Index> start;
        std::vector<Node> edges;
    public:
        MultiList() : edges(1, {0,0,0,0,0}) { ; }
        unsigned int NumVertices() { return start.size(); }
        unsigned int NumEdges() { return edges.size() - 1; }
        void addVertex(Vertex u)
        {
            if(start.size() <= u) { start.resize(u+1, NullIndex); }
        }
        void addEdge(Vertex u, Vertex v, Weight w);
        {
            addVertex(u < v ? v : u);
            edges.push_back({u, v, w, start[u], start[v]});
            start[u] = start[v] = edges.size() - 1;
        }
        Position begin(Vertex u);
        Position end(Vertex u);
};