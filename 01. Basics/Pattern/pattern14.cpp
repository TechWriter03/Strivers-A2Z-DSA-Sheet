// Input: 
// ‘N’ = 3
// Output: 
// A
// A B
// A B C

#include <bits/stdc++.h>
using namespace std;
void nLetterTriangle(int n) 
{
    for(int i=0;i<n;i++)
    {
        char ch='A';
        for(int j=0;j<=i;j++) 
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
