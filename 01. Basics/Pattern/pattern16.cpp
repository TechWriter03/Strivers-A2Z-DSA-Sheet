// Input: 
// ‘N’ = 3
// Output: 
// A
// B B
// C C C

#include <bits/stdc++.h>
using namespace std;
void alphaRamp(int n) 
{
    char ch='A';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++) cout<<ch<<" "; 
        ch++;
        cout<<endl;
    }
}
int main() 
{
    int n;
    cin>>n;
    alphaRamp(n);
    return 0;
}
