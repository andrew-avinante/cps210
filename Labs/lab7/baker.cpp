#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<string, int> PAIR;
struct cmp
    {
        bool operator()(const PAIR &a, const PAIR &b) { return (a.second != b.second) ? a.second >= b.second : a.first > b.first; };    //if the prices arent equal, compare the prices, else, compare their names
    };

int main() 
{
    int ingredientsNo, budget, recipes, binders;
    unordered_map<string, int> cookbook;    //stores the ingridients and their values
    unordered_map<string,priority_queue<PAIR, vector<PAIR>, cmp>> order;  //stores priority queue with binder name
    vector<string> bindering;   //keeps input in order
    cin >> binders;
    while (binders--)   //loop until binders equals 0
    {
        string binderName;
        priority_queue<PAIR, vector<PAIR>, cmp> inBudget;   //stores recipe price with recipe name ordered
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        getline(cin, binderName);
        bindering.push_back(binderName);
        cin >> ingredientsNo >> recipes >> budget;
        for(int i = 0; i < ingredientsNo; i++)
        {
            string ingName;
            int price;
            cin >> ingName >> price;
            cookbook[ingName] = price;
        }
        for(int i = 0; i < recipes; i++)
        {
            int counter, ingCnt;
            string recName;
            cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
            getline(cin, recName);
            cin >> ingCnt;
            int recipePrice = 0;
            PAIR price;
            for(int j = 0; j < ingCnt; j++)
            {
                string ingName;
                int ingQt;
                cin >> ingName >> ingQt;
                recipePrice += cookbook[ingName] * ingQt;
            }
            if(recipePrice <= budget)
            {
                price.first = recName;
                price.second = recipePrice;
                inBudget.push(price);
            }
        }
        order[binderName] = inBudget;
    }
    for(string i : bindering)
    {
        string title = "";
        for(char j : i)
        {
            title += toupper(j);
        }
        cout << title << endl;
        priority_queue<PAIR, vector<PAIR>, cmp> comparing = order[i];
        if(!comparing.empty())
        {
            for(int l = comparing.size() - 1; l < comparing.size(); l--)
            {
                cout << comparing.top().first << endl;
                comparing.pop();
            }
        }
        else
        {
            cout << "Too expensive!" << endl;
        }
        cout << endl;
    }
    return 0;
}