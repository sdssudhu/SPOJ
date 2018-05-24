// Submerging Islands

#include<bits/stdc++.h>
#define pb push_back
#define si(i) scanf("%d",&i)
#define MAX 10005
#define NIL -1
#define FOR(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int n,m;
int cont,times;
vector <int> v[MAX];
bool visited[MAX],ap[MAX];
int parent[MAX];
int low[MAX],disc[MAX];
void init()
{
    cont=0;
    times=0;
    FOR(i,0,MAX)
    {
      ap[i] = false;
      v[i].clear();
      visited[i]=false;
      parent[i]=NIL;
    }
}
int min(int a,int b)
{
  return a > b ? b : a;
}
void dfs(int u)
{
  int children=0;
  visited[u] = true;
  int l = v[u].size();
  disc[u] = low[u] = ++times;
  FOR(i,0,l)
  {
    int v1 = v[u][i];
    if(!visited[v1])
    {
      ++children;
      parent[v1] = u;
      dfs(v1);
      low[u] = min(low[u],low[v1]);
      if(parent[u] == NIL && children > 1)
        ap[true];
      if(parent[u] != NIL && disc[u] <= low[v1])
      {
        ap[u] = true;
          
          cont++;
      }
    }
    else
    if(v1 != parent[u])
      low[u] = min(low[u],disc[v1]);
  }
}
void fun()
{
  FOR(i,1,n+1)
    if(!visited[i])
      dfs(i);
}
int main()
{
  int a,b;
  while(1)
  {
    init();
    si(n);si(m);
    if(!n && !m)
      break;
    FOR(i,0,m)
    {
      si(a);si(b);
      v[a].pb(b);
      v[b].pb(a);
    }
    fun();
    cont=0;
    FOR(i,1,n+1)
      if(ap[i])
        cont++;
    cout<<cont<<endl;
  }
  return 0;
} 