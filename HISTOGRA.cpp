//Largest Rectangle in a Histogram

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	
	int n,i,j;
	while(true)
	{
	cin>>n;
	if(n==0)
	break;
	int ar[n],l[n],r[n];
	for(i=0;i<n;++i)
	cin>>ar[i],l[i]=-1,r[i]=n;
	
	stack<int> s;
	
	s.push(0);
	
	for(i=1;i<n;++i)
	{
	    while(!s.empty() && ar[s.top()]>ar[i])
	    {
	        r[s.top()]=i;
	        s.pop();
	    }
	    if(!s.empty())
	    l[i]=s.top();
	    s.push(i);
	}
	
	long long maxi=0;
	for(i=0;i<n;++i)
	{
	maxi=max(maxi,1LL*(r[i]-l[i]-1)*ar[i]);
	}
	cout<<maxi<<endl;
	}
	return 0;
}