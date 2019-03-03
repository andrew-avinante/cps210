#ifndef STACK_H
#define STACK_H
#include <vector>

template <typename T>
class Stack
{
    vector<T> vect;
    public:
        bool empty() const{return vect.empty();}
        void push(const T& val) {vect.push(val);}
        void pop()
        {
            if(!vect.empty())
            {
                vect.pop_back();
            }
        }
        const T &Top()
        {
            return vect.back();
        }
};

#endif