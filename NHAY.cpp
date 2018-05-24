// A Needle in the Haystack

#include <iostream>
using namespace std;
 
string text,pattern;
int lps[1000001],flag;
 
void Lps()
{
    int i,j;
    lps[0]=0;
    j=0;
    for(i=1;i<pattern.length();)
    {
        if(pattern[i]==pattern[j])
        {
            ++j;
            lps[i]=j;
            ++i;
        }
        else if(j!=0)
        j=lps[j-1];
        else
        {
            lps[i]=0;
            ++i;
        }
    }
}
 
void kmp()
{
    Lps();
    int i=0,j=0;
    for(i=0;i<text.length();)
    {
        if(pattern[j]==text[i])
        ++j,++i;
        if(j==pattern.length())
        {
            cout<<i-j<<endl;
            flag=1;
            j=lps[j-1];
        }
        else if(i<text.length() && pattern[j]!=text[i])
        {
             if (j != 0)
                j=lps[j-1];
            else
                i=i+1;
        }
    }
}
 
 
int main() 
{
    int m;
    while(cin>>m)
    {
        flag=0;
    cin>>pattern>>text;
    kmp();
    if(flag==0)
    cout<<endl;
    }
	return 0;
}