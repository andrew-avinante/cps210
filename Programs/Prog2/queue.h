#ifndef QUEUE_H
#define QUEUE_H
#include <vector>

template <typename T>
class Queue
{
    std::vector<T> values;
    public:
        Queue() { ; }
        inline bool empty() const { return values.empty(); }
        inline void push(const T& val) { values.push_back(val); };
        inline void pop()
        {
            if (!empty()) { values.erase(values.begin()); }
        }
        inline const T &front() const
        {
            return values[0];
        }
        inline int size() { return values.size();}
};

#endif