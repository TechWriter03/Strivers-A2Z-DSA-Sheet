// Input: 
// ‘N’ = 3
// Output: 
// 1
// 2 3
// 4 5 6

#include <bits/stdc++.h>
using namespace std;
void nNumberTriangle(int n) 
{
    int num=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

int main() 
{
    int n;
    cin>>n;
    nNumberTriangle(n);
    return 0;
}
