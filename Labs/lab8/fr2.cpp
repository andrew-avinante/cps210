#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

template<typename T>
class disjoint_set
{
private:
	struct set_node
	{
		pair<T, int> parent;
		std::size_t rank;
	};
	std::map<T, set_node> nodes;
    std::map<T, int> roots;

public:
	disjoint_set() {}
	~disjoint_set() {}

	void insert(const T& elem)
	{
		if (nodes.find(elem) == nodes.end())
		{
			set_node new_node{ {elem, 1}, size_t{0u} };
			nodes[elem] = new_node;
		}
	}

	std::pair<T, int> find(const T& node)
	{
		if (!(nodes[node].parent.first == node)) nodes[node].parent = find(nodes[node].parent.first);
		return nodes[node].parent;
	}

	//'union' cannot be used unfortunately
	void merge(const T& a, const T& b)
	{
		T a_root = find(a).first;
		T b_root = find(b).first;
		if (a_root == b_root) return;

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
        roots[find(a).first] = find(a).second;
	}
	int size(const T& node)
    {
        return find(node).second;
    }
    int GetMaxTree()
    {
        int max = 0;
        for (auto const& x : roots)
        {
            max = (max < x.second) ? x.second : max;
            //cout << max << endl;
        }
        return max;
    }
};

typedef std::pair<double, std::string> PAIR;
int main() 
{
    std::queue<int> ans;
    int cases, peopleCnt, count, cnt;
    std::cin >> cases;
    while (cases--)
    { 
        disjoint_set<std::string> sets;
        stdcin >> peopleCnt >> cnt;
        if(cnt != 0)    
        { 
            while (cnt--)
            {
                string p1, p2;
                cin >> p1 >> p2;
                sets.insert(p1);
                sets.insert(p2);
                sets.merge(p1,p2);
                //cout << sets.size() << endl;
            }
            ans.push(sets.GetMaxTree());
        }
        else
        {
            ans.push(1);
        }
    }
    while(!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop();
    }
    return 0;
}