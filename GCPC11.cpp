// Indiana Jones and the lost Soccer Cup

#include<bits/stdc++.h>
using namespace std;
int n,h,visited[10001],indeg[10001],outdeg[10001],mark[10001];
int dfs(vector<int> graph[],int s,int p)
{
    int i;
    mark[s]=visited[s]=1;
    for (i=0; i<graph[s].size(); i++)
    {
        if (p==0)
        {
            if (visited[graph[s][i]]==1 || (visited[graph[s][i]]==0 && dfs(graph,graph[s][i],p)==-1))
                return -1;
        }
        else if (p==1 && mark[graph[s][i]]==0)
            dfs(graph,graph[s][i],p);
    }
    visited[s]=2;
    if (p==1)
    cout<<s<<endl;
    return 0;
}
int main()
{
    int c;
    cin>>c;
    vector<int> graph[10001];
    while (c--)
    {
        scanf("%d%d",&n,&h);
        int i,z,y,f=0;
        z=y=n;
        for (i=1; i<=n; i++)
        {
            indeg[i]=outdeg[i]=mark[i]=visited[i]=0;
            graph[i].clear();
        }
        while(h--)
        {
            int a,b;
            cin>>a>>b;
            graph[b].push_back(a);
            if (indeg[b]==0)
                z--;
            if (outdeg[a]==0)
                y--;
            indeg[b]++;
            outdeg[a]++;
        }
 
        for (i=1; i<=n; i++)
        {
            if (visited[i]==0 && dfs(graph,i,0)==-1)
            {
                f=1;
                break;
            }
        }
        if (f==1)
        cout<<"recheck hints"<<endl;
        else if (z!=1 || y!=1)
        cout<<"missing hints"<<endl;
        else
        {
            for (i=1; i<=n; i++)
                mark[i]=0;
            for (i=1; i<=n; i++)
                if (mark[i]==0)
                    dfs(graph,i,1);
            cout<<endl;
        }
    }
    return 0;
} 