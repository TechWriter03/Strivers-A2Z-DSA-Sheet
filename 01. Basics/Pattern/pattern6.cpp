// Input: 
// ‘N’ = 3
// Output: 
// 1 2 3
// 1 2
// 1

#include<bits/stdc++.h>
using namespace std;
void nNumberTriangle(int n) 
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++) cout<<j<<" ";
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    nNumberTriangle(n);
    return 0;
}
