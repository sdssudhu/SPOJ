// Edit distance

#include<bits/stdc++.h>
using namespace std;
 
// Utility function to find minimum of three numbers
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
 
int dp[2001][2001];
int func(string str1, string str2, int m, int n)
{
 
 
 
 
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
 
            if (i==0)
                dp[i][j] = j; 
 
 
            else if (j==0)
                dp[i][j] = i; 
 
 
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            else
                dp[i][j] = 1 + min(dp[i][j-1], 
                                   dp[i-1][j],  
                                   dp[i-1][j-1]); 
        }
    }
 
    return dp[m][n];
}
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        string a,b;
        cin>>a>>b;
        cout<<func(a,b,a.length(),b.length())<<endl;
        --t;
    }
} 