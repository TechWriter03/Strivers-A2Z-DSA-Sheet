// Input: 
// ‘N’ = 3
// Output: 
// A B C
// A B
// A

#include <bits/stdc++.h>
using namespace std;
void nLetterTriangle(int n) 
{
    for(int i=n;i>0;i--)
    {
        char ch='A';
        for(int j=1;j<=i;j++)
        {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}

int main() 
{
    int n;
    cin>>n;
    nLetterTriangle(n);
    return 0;
}
