// Input:  
// ‘N’ = 3
// Output: 
// * 
// * *
// * * *

#include<bits/stdc++.h>
using namespace std;
void nForest(int n) 
{
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++) cout<<"* ";
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    nForest(n);
    return 0;
}
