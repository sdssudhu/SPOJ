// True Friends

#include <bits/stdc++.h>
using namespace std;
 
vector<int> v[200];
vector<pair<int,int> >vec;
int visited[200];
int ctr;
 
void dfs(int i)
{
    visited[i]=1;
    for(int j=0;j<v[i].size();++j)
    if(visited[v[i][j]]==0)
    {
        ++ctr;
        dfs(v[i][j]);
    }
    ++ctr;
    vec.push_back({i,ctr});
}
 
bool comp(pair<int,int> i,pair<int,int> j)
{
    return i.second>j.second;
}
 
int main() {
	int t,n,i,j;
	cin>>t;
	while(t>0)
	{
	    cin>>n;
	    char ch[n][n];
	    vec.clear();
	    ctr=0;
	    for(i=0;i<=n;++i)
	    v[i].clear(),visited[i]=0;
	    for(i=0;i<n;++i)
	    cin>>ch[i];
	    for(i=0;i<n;++i)
	    for(j=0;j<n;++j)
	    if(ch[i][j]=='Y')
	    v[i+1].push_back(j+1);
	    for(i=1;i<=n;++i)
	    {
	        if(visited[i]==0)
	        {
	        dfs(i);
	        }
	    }
	    for(i=0;i<=n;++i)
	    v[i].clear(),visited[i]=0;
	    for(i=0;i<n;++i)
	    for(j=0;j<n;++j)
	    if(ch[i][j]=='Y')
	    v[j+1].push_back(i+1);
	    int count=0;
	    sort(vec.begin(),vec.end(),comp);
	    for(i=0;i<n;++i)
	    if(visited[vec[i].first]==0)
	    {
	        dfs(vec[i].first);
	        ++count;
	    }
	    cout<<count<<endl;
	    --t;
	}
	return 0;
}