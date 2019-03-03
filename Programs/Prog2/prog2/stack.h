#ifndef STACK_H
#define STACK_H
#include <vector>

template <typename T>
class Stack
{
    std::vector<T> values;
    public:
        Stack() { ; }
        inline bool empty() const { return values.empty(); }
        inline void push(const T& val) { values.push_back(val); };
        inline void pop()
        {
            if (!empty()) { values.pop_back(); }
        }
        inline const T &top() const
        {
            return values.back();
        }
        inline int size() { return values.size();}
};

#endif