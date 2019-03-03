#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include "stack.h"
using namespace std;

double Exp(double x, unsigned int n)
{
    int ans((n & 1) ? x : 1);
    int powerOfX(x * x);
    for (n >>= 1; n; n >>= 1, powerOfX *= powerOfX)
    {
        if (n & 0x01) {ans *= powerOfX;}
    }
    return ans;
}

class ExpressionTree
{
    public:
        struct Node
        {
            string token;
            Node *left;
            Node *right;
            Node(const string &_token, Node *_left=nullptr, Node *_right=nullptr):
                token(_token), left(_left), right(_right) {;}
            ~Node()
            {
                if(left) { delete left; }
                if (right) { delete right; }
                left = right = nullptr;
            }
            bool isLeaf() const {return (nullptr == left && nullptr == right);}
            double eval()
            {
                switch(token[0])
                    {
                    case '+': 
                    {
                        return left->eval() + right->eval();
                    }
                    break;
                    case '-': 
                    {
                        return left->eval() - right->eval();
                    }
                    break;
                    case '*':
                    {
                        return left->eval() * right->eval();
                    }
                    break;
                    case '/':
                    {
                        return left->eval() / right->eval();
                    }
                    break;
                    case '%':
                    {
                        return (int)left->eval() % (int)right->eval();
                    }
                    break;
                    case '^': 
                    {
                        return Exp(left->eval(), right->eval());
                    }
                    break;
                    default:      
                        return (isdigit(token[0])) ?  stod(token) : token.size();
                    break;
                }
            }
        };
          
    private:
        Node *root;
        ExpressionTree(Node *_root) : root(_root) {;}
    public:
        static ExpressionTree *build(const string &exp);
        bool isEmpty() const {return (nullptr == root);}
        double eval(){return (isEmpty() ? 0.0 : root->eval());}
        friend ostream &operator <<(ostream &os, const ExpressionTree &tree);
        ~ExpressionTree(){}
};

ostream &operator <<(ostream &os, const ExpressionTree::Node &node)
{
    if(node.left != nullptr)
    {
        os << node.token;
        os << "(";
        os << *node.left;
    }
    if(node.right != nullptr && node.left != nullptr)
    {
        os << ",";
        os << *node.right;
        os << ")";
    }
    if(node.isLeaf())
    {
        os << node.token;
    }
    return os;
}
ostream &operator <<(ostream &os, const ExpressionTree &tree)
{
    os << "(";
    if (!tree.isEmpty())
    {
        os << *(tree.root);
    }
    os << ")";
    return os;
}

ExpressionTree *ExpressionTree::build(const string &exp)
{
    Stack<Node*> stuff;
    istringstream iss(exp);
    string token;
    while(iss >> token)
    {
        switch(token[0])
        {
            case '+': 
            {
                if(stuff.empty()){throw "The stack is empty!";}
                Node *right = stuff.top();
                stuff.pop();
                if(stuff.empty()){throw "The stack is empty!";}
                Node *left = stuff.top();
                stuff.pop();
                stuff.push(new Node(token, left, right));
            }
            break;
            case '-': 
            {
                if(stuff.empty()){throw "The stack is empty!";}
                Node *right = stuff.top();
                stuff.pop();
                if(stuff.empty()){throw "The stack is empty!";}
                Node *left = stuff.top();
                stuff.pop();
                stuff.push(new Node(token, left, right));
            }
            break;
            case '*':
            {
                if(stuff.empty()){throw "The stack is empty!";}
                Node *right = stuff.top();
                stuff.pop();
                if(stuff.empty()){throw "The stack is empty!";}
                Node *left = stuff.top();
                stuff.pop();
                stuff.push(new Node(token, left, right));
            }
            break;
            case '/':
            {
                if(stuff.empty()){throw "The stack is empty!";}
                Node *right = stuff.top();
                stuff.pop();
                if(stuff.empty()){throw "The stack is empty!";}
                Node *left = stuff.top();
                stuff.pop();
                stuff.push(new Node(token, left, right));
            }
            break;
            case '%':
            {
                if(stuff.empty()){throw "The stack is empty!";}
                Node *right = stuff.top();
                stuff.pop();
                if(stuff.empty()){throw "The stack is empty!";}
                Node *left = stuff.top();
                stuff.pop();
                stuff.push(new Node(token, left, right));
            }
            break;
            case '^': 
            {
                if(stuff.empty()){throw "The stack is empty!";}
                Node *right = stuff.top();
                stuff.pop();
                if(stuff.empty()){throw "The stack is empty!";}
                Node *left = stuff.top();
                stuff.pop();
                stuff.push(new Node(token, left, right));
            }
            break;
            default:
                stuff.push(new Node(token));
            break;
        }
    }
    return new ExpressionTree(stuff.empty() ? nullptr : stuff.top());

}

void processExpression(string &exp)
{
    ExpressionTree *et = ExpressionTree::build(exp);
    cout << "The expression tree is: " << *et << endl << "and its value is " << et->eval() << endl;
    delete et;
}


int main()
{
	string buffer;
	while (getline(cin,buffer))
    {
        try
        {
            processExpression(buffer);
        }
        catch (const char* c)
        {
            cout << c << endl;
        }
	}
    
	return 0;
}