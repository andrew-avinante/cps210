#include <iostream>
#include <vector>

using namespace std;

template <typename Number>
Number fastExp1(Number x, unsigned int n)
{
    switch(n)
    {
        case 0: return Number(1);
        case 1: return x;
        case 2: return (x * x);
        case 3: return (x * x * x);
    }
    Number ans = fastExp1(x, n >> 1);
    ans *= ans;
    if (n & 0x01) { ans *= x; } 
    return ans;
}

//Recursive
template <typename Number>
Number fastExp2(Number x, unsigned int n)
{
    switch(n)
    {
        case 0: return Number(1);
        case 1: return x;
        case 2: return (x * x);
        case 3: return (x * x * x);
    }
    Number ans = fastExp2(x * x, n >> 1);
    if (n & 0x01) { ans *= x; } 
    return ans;
}

template <typename Number>
Number fastExp3(Number x, unsigned int n)
{
    switch(n)
    {
        case 0: return Number(1);
        case 1: return x;
        case 2: return (x * x);
        case 3: return (x * x * x);
    }
    Number ans = fastExp2(x * x, n >> 1);
    if (n & 0x01) { ans *= x; } 
    return ans;
}

template <typename Number>
Number fastExp4(Number x, unsigned int n)
{
    Number ans((n & 1) ? x : 1);
    Number powerOfX(x * x);
    for (n >>= 1; n; n >>= 1, powerOfX *= powerOfX)
    {
        if (n & 0x01) {ans *= powerOfX;}
    }
    return ans;
}

// The lsb to msb
template <typename T, typename Iter>
T fastExp5(T &x, Iter lsb, Iter onePastMsb)
{
    if (onePastMsb == lsb) {
        return ((*lsb) ? x : T(1));
    }
    T ans = 1;
    T xToPowerOf2 = x;
    for (; lsb < onePastMsb; ++lsb, xToPowerOf2 *= xToPowerOf2) {
        if(*lsb){ans*=xToPowerOf2;}
    }
    return ans;
}

template <typename T, typename Iter>
T fastExp6(T &x, Iter msb, Iter lsb) {
    for (; msb != lsb && !(*msb); ++msb) { ; }
    if (msb == lsb) { return T(1); }
    T ans(x);
    for (++msb; msb != lsb; ++msb) {
        ans *= ans;
        if (*msb) { ans *= x; }
    }
    return ans;
}

int main()
{
    vector<int> num = {1,0,1,0};
    int base = 2;
    cout << fastExp1(2, 10) << endl;
    cout << fastExp2(2, 10) << endl;
    cout << fastExp3(2, 10) << endl;
    cout << fastExp4(2, 10) << endl;
    cout << fastExp5(base, num.rbegin(), num.rend()) << endl;
    cout << fastExp6(base, num.begin(), num.end()) << endl;
    return 0;
}