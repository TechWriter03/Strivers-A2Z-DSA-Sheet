// Input: 
// ‘N’ = 3
// Output: 
//   *
//  ***
// *****

#include<bits/stdc++.h>
using namespace std;
void nStarTriangle(int n) 
{
    int space=n-1;
    for(int i=1;i<=n;i++)
    {
        for(int sp=space;sp>0;sp--) cout<<" ";
        for(int j=1;j<=2*i-1;j++) cout<<"*";
        for(int sp=space;sp>0;sp--) cout<<" ";
        cout<<"\n";
        space--;
    }
}
int main()
{
    int n;
    cin>>n;
    nStarTriangle(n);
    return 0;
}
