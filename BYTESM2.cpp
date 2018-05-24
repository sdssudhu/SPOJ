// Philosophers Stone

#include <iostream>
using namespace std;
 
int main() {
	long long t;
	cin>>t;
	while(t>0)
	{
	    long long h,w,i,j;
	    cin>>h>>w;
	    long long ar[h][w],dp[h][w];
	    long long ans;
	    for(i=0;i<h;++i)
	    for(j=0;j<w;++j)
	    cin>>ar[i][j];
	    for(i=0;i<w;++i)
	    dp[h-1][i]=ar[h-1][i];
	    for(i=h-2;i>=0;--i)
	    {
	    dp[i][0]=ar[i][0]+max(dp[i+1][0],dp[i+1][1]);
	    dp[i][w-1]=ar[i][w-1]+max(dp[i+1][w-1],dp[i+1][w-2]);
	    for(j=1;j<w-1;++j)
	    dp[i][j]=ar[i][j]+max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]));
	    }
	    ans=0;
	    for(i=0;i<w;++i)
	    ans=max(ans,dp[0][i]);
	    cout<<ans<<endl;
	    --t;
	}
	return 0;
}