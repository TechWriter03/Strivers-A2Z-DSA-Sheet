// Input: 
// ‘N’ = 3
// Output: 
// *         *
// * *     * *
// * * * * * *
// * *     * *
// *         *

#include <bits/stdc++.h>
using namespace std;
void symmetry(int n) 
{
    int row=(2*n)-1,sp=n+1,star=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<star;j++) cout<<"* ";
        for(int j=0;j<sp;j++) cout<<"  ";
        for(int j=0;j<star;j++) cout<<"* ";
        if(i<row/2)
        {
            star++;
            sp-=2;
        }
        else
        {
            star--;
            sp+=2;
        }
        cout<<endl;
    }
}

int main() 
{
    int n;
    cin>>n;
    symmetry(n);
    return 0;
}
