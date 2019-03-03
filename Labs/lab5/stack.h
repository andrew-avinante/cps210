#ifndef STACK_H
#define STACK_H
#include <vector>

template <typename T>
class Stack
{
    std::vector<T> values;
    public:
        Stack() { ; }
        bool empty() const { return values.empty(); }
        void push(const T& val) { values.push_back(val); };
        void pop()
        {
            if (!empty()) { values.pop_back(); }
        }
        T &top() const
        {
            return  values.back();
        }
};

#endif