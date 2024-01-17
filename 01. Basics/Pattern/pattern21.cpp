// Input: 
// ‘N’ = 4
// Output: 
// ****
// *  *
// *  *
// ****

#include <bits/stdc++.h>
using namespace std;
void getStarPattern(int n) 
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) i==0||i==n-1||j==0||j==n-1? cout<<"*":cout<<" ";
        cout<<"\n";
    }
}

int main() 
{
    int n;
    cin>>n;
    getStarPattern(n);
    return 0;
}
