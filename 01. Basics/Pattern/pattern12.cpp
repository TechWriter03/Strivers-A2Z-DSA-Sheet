// Input: 
// ‘N’ = 3
// Output: 
// 1         1
// 1 2     2 1
// 1 2 3 3 2 1

#include <bits/stdc++.h>
using namespace std;
void numberCrown(int n) 
{
    int sp=2*(n-1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++) cout<<j<<" ";
        for(int k=1;k<=sp;k++) cout<<"  ";
        for(int j=i;j>0;j--) cout<<j<<" ";
        sp-=2;
        cout<<"\n";
    }
}
int main() 
{
    int n;
    cin>>n;
    numberCrown(n);
    return 0;
}
