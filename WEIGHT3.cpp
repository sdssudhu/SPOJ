// VEGETABLE SHOPKEEPER 3

#include <bits/stdc++.h>
using namespace std;
long long n,w;
long long mini=1e9+7;
long long ar[110];
void func()
{
    int flag=0;
    long long dp[n+1][w+1];
    long long i,j;
    for(i=0;i<=n;++i)
    for(j=0;j<=w;++j)
    dp[i][j]=0;
    for(i=0;i<n;++i)
    {
        if(ar[i]>=w)
        {
        mini=min(mini,ar[i]-w);
        if(flag!=0)
        for(j=0;j<w;++j)
        dp[i][j]=dp[i][j]+dp[i-1][j];
        continue;
        }
        if(flag==0)
        {
            dp[i][ar[i]]=1;
            flag=1;
            continue;
        }
        for(j=0;j<w;++j)
        dp[i][j]=dp[i][j]+dp[i-1][j];
        for(j=0;j<w;++j)
        if(dp[i][j]!=0)
        {
        if(j+ar[i]>=w)
        {
        mini=min(mini,j+ar[i]-w);
        }
        }
        for(j=0;j<w;++j)
        if(j+ar[i]<w)
        dp[i][j+ar[i]]+=dp[i-1][j];
        else
        break;
        ++dp[i][ar[i]];
    }
}
 
 
 
int main() {
	long long t,i;
	cin>>t;
	while(t>0)
	{
	    mini=1e9+7;
	    cin>>n>>w;
	    for(i=0;i<n;++i)
	    cin>>ar[i];
	    func();
	    cout<<mini<<endl;
	    --t;
	}
	return 0;
}   