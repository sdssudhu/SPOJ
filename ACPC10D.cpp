//Tri Graphs -- SPOJ

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long n,i,j;
	int x=1,k=1;
	while(x!=0)
	{
	cin>>n;
	if(n==0)
	break;
	long long a[n+1][3];
	long long dp[n+1][3];
	for(i=0;i<n;++i)
	for(j=0;j<3;++j)
	{
	    cin>>a[i][j];
	    dp[i][j]=0;
	}
	dp[n-2][2]=a[n-2][2]+a[n-1][1];
	dp[n-2][1]=min(a[n-2][1]+a[n-1][1],a[n-2][1]+dp[n-2][2]);
	dp[n-2][1]=min(dp[n-2][1],a[n-2][1]+a[n-1][0]+a[n-1][1]);
	dp[n-2][0]=min(a[n-2][0]+a[n-1][1],min(a[n-2][0]+a[n-1][0]+a[n-1][1],a[n-2][0]+dp[n-2][1]));
	for(i=n-3;i>=0;--i)
	{
	    dp[i][2]=a[i][2]+min(dp[i+1][1],dp[i+1][2]);
	    dp[i][1]=a[i][1]+min(dp[i+1][0],min(dp[i+1][1],dp[i+1][2]));
	    dp[i][1]=min(dp[i][1],a[i][1]+dp[i][2]);
	    dp[i][0]=a[i][0]+min(dp[i+1][0],dp[i+1][1]);
	    dp[i][0]=min(dp[i][0],a[i][0]+dp[i][1]);
	}
	long long ans=dp[0][1];
	cout<<k<<". "<<ans<<endl;
	++k;
	}
	return 0;
}