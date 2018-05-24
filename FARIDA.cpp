// Princess Farida

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long t,k=1;
	cin>>t;
	while(t>0)
	{
	    long long n;
	    cin>>n;
	    long long a[n],ans[n];
	    for(int i=0;i<n;++i)
	    cin>>a[i];
	    for(int i=0;i<n;++i)
	    {
	        if(i==0)
	        ans[i]=a[i];
	        else if(i==1)
	        ans[i]=max(a[0],a[i]);
	        else
	        ans[i]=max(ans[i-2]+a[i],ans[i-1]);
	    }
	    if(n!=0)
	    cout<<"Case "<<k<<": "<<ans[n-1]<<endl;
	    else
	    cout<<"Case "<<k<<": "<<0<<endl;
	    ++k;
	    --t;
	}
	return 0;
}
 

