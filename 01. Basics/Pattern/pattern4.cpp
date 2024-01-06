// Input: 
// ‘N’ = 3
// Output: 
// 1
// 2 2 
// 3 3 3

#include<bits/stdc++.h>
using namespace std;
void triangle(int n) 
{
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++) cout<<i<<" ";
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    triangle(n);
    return 0;
}
