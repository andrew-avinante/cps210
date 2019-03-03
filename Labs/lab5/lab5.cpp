#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include "stack.h"
using namespace std;

string infixToPostfix(const string &instr)
{
	ostringstream oss;
	Stack<char> ops;
	for (char c : instr)
    {
		if (isspace(c)) { continue; }
		switch (c)
        {
		case '+': 
            if(!ops.empty() && ops.top() != '(')
            {
                while(!ops.empty() && ops.top() != '(')
                {
                    oss << ops.top() << ' ';
                    ops.pop();    
                }
                ops.push(c);
            }
            else
            {
                ops.push(c);
            }
        break;
		case '-': 
            if(!ops.empty() && ops.top() != '(')
            {
                while(!ops.empty() && ops.top() != '(')
                {
                    oss << ops.top() << ' ';
                    ops.pop();    
                }
                 ops.push(c);
            }
            else
            {
                ops.push(c);
            }
        break;
		case '*':
            if(!ops.empty() && ops.top() != '(' && ops.top() != '+' && ops.top() != '-')
            {
                while(!ops.empty() && ops.top() != '(' && ops.top() != '+' && ops.top() != '-')
                {
                    oss << ops.top() << ' ';
                    ops.pop();    
                }
                 ops.push(c);
            }
            else
            {
                ops.push(c);
            }
        break;
		case '/':
            if(!ops.empty() && ops.top() != '(' && (ops.top() != '+' && ops.top() != '-'))
            {
                while(!ops.empty() && ops.top() != '(' && ops.top() != '+' && ops.top() != '-')
                {
                    oss << ops.top() << ' ';
                    ops.pop();    
                }
                 ops.push(c);
            }
            else
            {
                ops.push(c);
            }
        break;
		case '%':
            if(!ops.empty() && ops.top() != '(' && ops.top() != '+' && ops.top() != '-')
            {
                while(!ops.empty() && ops.top() != '(' && ops.top() != '+' && ops.top() != '-')
                {
                    oss << ops.top() << ' ';
                    ops.pop();    
                }
                 ops.push(c);
            }
            else
            {
                ops.push(c);
            }
        break;
		case '^': 
			ops.push('^');
			break;
		case '(':
			ops.push('(');
			break;
		case ')':
			while (!ops.empty() && ops.top() != '(')
            {
				oss << ops.top() << ' ';
				ops.pop();
			}
			if (ops.empty())
            {
				throw string("Stack is empty");
			}
            if(ops.top() != '(')
            {
                throw "Missing '('";
            }
			ops.pop(); // remove the opening parenthesis
			break;
		default:
			oss << c << ' ';
		}
	}
    while(!ops.empty())
    {
        if(ops.top() == '(')
        {
            throw "Missing ')'";
        }
        oss << ops.top() << ' ';
		ops.pop();
    }
	return oss.str();
}

int main()
{
	string buffer;
	while (getline(cin,buffer))
    {
        if(buffer == "q")
        {
            return 0;
        }
        try
        {
		    cout << infixToPostfix(buffer) << endl;
        }
        catch (const char* c)
        {
            cout << c;
        }
	}
	return 0;
}