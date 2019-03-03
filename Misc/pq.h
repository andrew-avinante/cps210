#define PRIORITY_QUEUE
#include <iostream>
#include <vector>

//maximum pq
template<typename T, typename Compare=std::less<T>>
class PriorityQueue
{
    const int d; // the max number of children per node
    std::vector<T> heap;
    Compare cmp;

    bool atRoot(int k) const { return (0 == k); }
    int parent (int k) const { return (k-1)/d; }
    int lastParent() const { return parent(size() - 1); }
    bool atLeaf(int k) const { return (k > lastParent()); }

    int firstChild(int k) { return (k * d + 1); }
    int lastChild(int k) { return ((k + 1) * d) >= size() ? size()-1 : (k+1)*d;}
    int maxChild(int k)
    {
        int maxC = firstChild(k);
        int lastC = lastChild(k);
        for (int k = maxC + 1; k <= lastC; ++k)
        {
            if (cmp(heap[maxC], heap[k]))
            {
                maxC = k;
            }
        }
        return maxC;
    }

    void moveUp(int k)
    {
        while(!atRoot(k) && cmp(heap[parent(k)], heap[k]))
        {
            swap(heap[parent(k)], heap[k]);
            k = parent(k);
        }
    }
    void moveDown(int k)
    {
        while(!atLeaf(k))
        {
            int maxC = maxChild(k);
            if(!cmp(heap[k], heap[maxC])){ break; }
            swap(heap[maxC], heap[k]);
            k = maxC;
        }
    }
    public:
        PriorityQueue(int _d=4) : d(_d) { ; }
        bool empty() const { return heap.empty();}
        unsigned int size() const {return heap.size();}
        void push(const T&val)
        {
            heap.push_back(val);
            moveUp(size() - 1);
        }
        const T& top() const{ return heap[0]; }
        void pop()
        {
            if (empty()){ return; }
            if (size() > 1)
            {
                heap [0] = heap.last();
                heap.pop_back();
                moveDown(0);
            }
        }
};