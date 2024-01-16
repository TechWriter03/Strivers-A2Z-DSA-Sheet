// Input: 
// ‘N’ = 3
// Output: 
// 1
// 0 1
// 1 0 1

#include <bits/stdc++.h>
using namespace std;
void nBinaryTriangle(int n) 
{
    int b;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1) b=1;
        else b=0;
        for(int j=1;j<=i;j++)
        {
            cout<<b<<" ";
            b=1-b;
        }
        cout<<endl;
    }
}

int main() 
{
    int n;
    cin>>n;
    nBinaryTriangle(n);
    return 0;
}
