// I AM VERY BUSY

#include <bits/stdc++.h>
using namespace std;
 
bool comp(pair<int,int> i,pair<int,int> j)
{
    return i.second<j.second;
}
vector<pair<int,int> >v;
int main() {
	int t;
	cin>>t;
	while(t>0)
	{
	    int i,n,a,b;
	v.clear();
	cin>>n;
	for(i=0;i<n;++i)
	{
	    cin>>a>>b;
	    v.push_back({a,b});
	}
	sort(v.begin(),v.end(),comp);
	long long ct=1;
	long long end=v[0].second;
	for(i=1;i<n;++i)
	{
	    if(end<=v[i].first)
	    {
	        ++ct;
	        end=v[i].second;
	    }
	}
	cout<<ct<<endl;
	--t;
	}
	return 0;
}