// Input: 
// ‘N’ = 3
// Output: 
//     A
//   A B A
// A B C B A

#include <bits/stdc++.h>
using namespace std;
void alphaHill(int n) 
{
    int sp=2*(n-1);
    for(int i=0;i<n;i++)
    {
        char ch='A';
        for(int k=1;k<=sp;k++) cout<<" ";
        for(int j=0;j<(2*i+1);j++)
        {
            cout<<ch<<" ";
            if(j>=(2*i+1)/2) ch--;
            else ch++;
        }
        for(int k=1;k<=sp;k++) cout<<" ";
        sp-=2;
        cout<<endl;
    }
}
int main() 
{
    int n;
    cin>>n;
    alphaHill(n);
    return 0;
}
