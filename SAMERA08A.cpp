// Almost Shortest Path

#include<bits/stdc++.h>
using namespace std;
 
const int inf = (1 << 30) - 1;
 
vector < vector < int > > graph;
vector < vector < int > > paths;
 
vector < int > vi;
 
int adjm[501][501];
 
int n, m, start, finish;
 
void dijkstra()
{
    set < pair < int, int > > ordered;
    ordered.insert(make_pair(0, start));
 
    vector < int > dist(n, inf);
    dist[start] = 0;
 
    int node, cost;
    while (!ordered.empty())
    {
        cost = (*ordered.begin()).first;
        node = (*ordered.begin()).second;
 
        ordered.erase(ordered.begin());
 
        for (int i = 0; i < graph[node].size(); i++)
        {
            int newn = graph[node][i];
            int newc = adjm[node][newn];
 
            if (cost + newc <= dist[newn])
            {
                if (cost + newc < dist[newn])
                {
                    paths[newn].clear();
                }
 
                paths[newn].push_back(node);
 
                if (dist[newn] != inf)
                {
                    ordered.erase(make_pair(dist[newn], newn));
                }
                dist[newn] = cost + newc;
                ordered.insert(make_pair(dist[newn], newn));
            }
        }
    }
}
 
void removeroads(int node)
{
    for (int i = 0; i < paths[node].size(); i++)
    {
        int neigh = paths[node][i];
        adjm[neigh][node] = -1;
        removeroads(neigh);
    }
}
 
int dijkstra2()
{
    set < pair < int, int > > ordered;
    ordered.insert(make_pair(0, start));
 
    vector < int > dist(n, inf);
    dist[start] = 0;
 
    int node, cost;
    while (!ordered.empty())
    {
        cost = (*ordered.begin()).first;
        node = (*ordered.begin()).second;
 
        if (node == finish)
        {
            return cost;
        }
 
        ordered.erase(ordered.begin());
 
        for (int i = 0; i < graph[node].size(); i++)
        {
            int newn = graph[node][i];
            int newc = adjm[node][newn];
 
            if (newc == -1) continue; // path is deleted
 
            if (cost + newc < dist[newn])
            {
                if (dist[newn] != inf)
                {
                    ordered.erase(make_pair(dist[newn], newn));
                }
                dist[newn] = cost + newc;
                ordered.insert(make_pair(dist[newn], newn));
            }
        }
    }
 
    return -1;
}
 
int main()
{
    while (true)
    {
        scanf("%d %d", &n, &m);
 
        if (n + m == 0)
        {
            return 0;
        }
 
        scanf("%d %d", &start, &finish);
 
        graph.insert(graph.begin(), n, vi);
        paths.insert(paths.begin(), n, vi);
 
        int a, b, c;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            graph[a].push_back(b);
            adjm[a][b] = c;
        }
 
        dijkstra();
 
        removeroads(finish);
 
        printf("%d\n", dijkstra2());
 
        graph.clear();
        paths.clear();
    }
 
    return 0;
} 