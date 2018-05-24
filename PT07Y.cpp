// Is it a tree

#include <bits/stdc++.h>
using namespace std;
 
vector <int> v[200100];
int visited[200100];
void dfs(int i)
{
    visited[i]=1;
    for(int j=0.;j<v[i].size();++j)
    if(visited[v[i][j]]==0)
    dfs(v[i][j]);
}
int main() {
	int n,m,i,a,b;
	cin>>n>>m;
	int flag=1;
	for(i=0;i<m;++i)
	{
	    cin>>a>>b;
	    if(a!=b)
	    {
	    v[a].push_back(b);
	    v[b].push_back(a);
	    }
	}
	if(m!=n-1)
	flag=0;
	for(i=1;i<=n;++i)
	{
	visited[i]=0;
	if(v[i].size()==0)
	flag=0;
	}
	int k=0;
	for(i=1;i<=n;++i)
	{
	    if(visited[i]==0)
	    {
	        dfs(i);
	        ++k;
	    }
	}
	if(k>1)
	flag=0;
	if(flag==0)
	cout<<"NO"<<endl;
	else
	cout<<"YES"<<endl;
	return 0;
}