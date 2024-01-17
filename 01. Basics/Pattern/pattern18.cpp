// Input: 
// ‘N’ = 3
// Output: 
// C
// C B 
// C B A

#include <bits/stdc++.h>
using namespace std;
void alphaTriangle(int n) 
{
    for(int i=0;i<n;i++)
    {
        int c=65+(n-1);
        for(int j=0;j<=i;j++) 
        {
            char ch=(char)c;
            cout<<ch<<" "; 
            c--;
        }
        cout<<endl;
    }
}
int main() 
{
    int n;
    cin>>n;
    alphaTriangle(n);
    return 0;
}
