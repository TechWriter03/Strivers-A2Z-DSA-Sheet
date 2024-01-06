// You are given a number ’n’.
// Find the number of digits of ‘n’ that evenly divide ‘n’.
// Input: ‘n’ = 336
// Output: 3

#include<bits/stdc++.h>
using namespace std;
int countDigits(int n)
{
    int m=n,c=0,ld;
    while(n!=0)
    {
        ld=n%10;
        if(ld==0)
        {
            n/=10;
            continue;
        }
        if(m%ld==0) c++;
        n/=10;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    cout<<countDigits(n);
    return 0;
}
