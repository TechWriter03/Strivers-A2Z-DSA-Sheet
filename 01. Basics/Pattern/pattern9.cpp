// Input: 
// ‘N’ = 3
// Output: 
//   *
//  ***
// *****
// *****
//  ***
//   *

#include<bits/stdc++.h>
using namespace std;
void nStarDiamond(int n) 
{
    int s1=0,s2=n-1;
    for(int i=1;i<=n;i++)
    {
        for(int sp=s2;sp>0;sp--) cout<<" ";
        for(int j=1;j<=2*i-1;j++) cout<<"*";
        for(int sp=s2;sp>0;sp--) cout<<" ";
        cout<<"\n";
        s2--;
    }
    for(int i=n;i>=1;i--)
    {
        for(int sp=0;sp<s1;sp++) cout<<" ";
        for(int j=2*i-1;j>=1;j--) cout<<"*";
        for(int sp=0;sp<=s1;sp++) cout<<" ";
        cout<<"\n";
        s1++;
    }
}

int main()
{
    int n;
    cin>>n;
    nStarDiamond(n);
    return 0;
}
