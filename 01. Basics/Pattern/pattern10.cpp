// Input: 
// ‘N’ = 3
// Output: 
// *
// **
// ***
// **
// *

#include<bits/stdc++.h>
using namespace std;
void nStarTriangle(int n) 
{
    int st=1;
    for(int i=1;i<=2*n-1;i++)
    {
        for(int j=1;j<=st;j++) cout<<"*";
        cout<<"\n";
        if(i>(2*n-1)/2) st--;
        else st++;
    }
}

int main()
{
    int n;
    cin>>n;
    nStarTriangle(n);
    return 0;
}
