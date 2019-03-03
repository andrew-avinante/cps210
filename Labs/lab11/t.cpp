#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int mincost(bool mstset[], int cost[],int v)

{

int min=INT_MAX;

int u;

for(int i=0; i<v; i++)

{

if(mstset[i]==false&&cost[i]<

min)

{

min=cost[i];

u=i;

}

}

return u;

}

void kruskal(priority_queue<pair<

int,int> > q[],bool mstset[],int parent[],int cost[],int v)

{

for(int i=0; i<v-1; i++)

{

int u=mincost(mstset,cost,v);

cout<<"min key"<<u<<endl;

mstset[u]=true;

pair<int, int> p;

while(!q[u].empty())

{

p=q[u].top();

q[u].pop();

if(mstset[p.first]==false&&

cost[p.first]>p.second)

{

cost[p.first]=p.second;

parent[p.first]=u;

cout<<"updated cost of "<<p.first<<"is "<<cost[p.first]<<endl;

}

}

}

}

int main()

{

int v,e;

cin>>v>>e;

priority_queue<pair<int,int> > q;

for(int i=0; i<e; i++)

{

int x,y,z;

cin>>x>>y>>z;

q.push(make_pair(y,z));

q.push(make_pair(x,z));

}

bool mstset[v];

int parent[v],cost[v];

for(int i=0; i<v; i++) mstset[i]=false;

for(int i=0; i<v; i++) parent[i]=-1;

for(int i=0; i<v; i++) cost[i]=INT_MAX;

cost[0]=0;

parent[0]=-1;

kruskal(q,mstset,parent,cost,

v);

for(int i=1;i<v;i++)

cout<<i<<" "<<parent[i]<<endl;

}