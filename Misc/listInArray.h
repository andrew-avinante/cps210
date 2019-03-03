#include <vector>

template <typename T>
class List
{
    public:
        typedef int Link;
        struct Node
        {
            T value;
            Link next, prev;
        };
    
    private:
        std::vector<Node> nodes;
        Link free_lnk;

    public:
        Link insert(T value, Link pos)
        {
            if(0 == free)
            {
                free_lnk = nodes.size;
                nodes.push_back({value,0,0});
            }
            Link curr = free_lnk;
            free_lnk = nodes[curr].next;
            nodes[curr].next = pos;
            nodes[curr].prev = nodes[pos].prev;
            nodes[nodes[pos].prev].next = curr;
        }
};