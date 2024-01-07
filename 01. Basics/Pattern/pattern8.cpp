// Input: 
// ‘N’ = 3
// Output: 
// *****
//  ***
//   *
    
#include<bits/stdc++.h>
using namespace std;
void nStarTriangle(int n) 
{
    int space=0;
    for(int i=n;i>=1;i--)
    {
        for(int sp=0;sp<space;sp++) cout<<" ";
        for(int j=2*i-1;j>=1;j--) cout<<"*";
        for(int sp=0;sp<=space;sp++) cout<<" ";
        cout<<"\n";
        space++;
    }
}
int main()
{
    int n;
    cin>>n;
    nStarTriangle(n);
    return 0;
}
