// Input: 
// ‘N’ = 3
// Output: 
// 33333
// 32223
// 32123
// 32223
// 33333

#include <bits/stdc++.h>
using namespace std;
void getNumberPattern(int n) 
{
    int row=(2*n)-1,x=-1,y=row,m=n;
    vector<int>a(row,n);
    while(x<row||y>0)
    {
        if(x==row/2)
        {
            x++;
            y--;
            m++;
            continue;
        }
        if(x<y)
        {
            for(int i=x+1;i<y;i++) a[i]=m;
            m--;
        }
        else
        {
            m++;
            for(int i=y+1;i<x;i++) a[i]=m;
        }
        for(auto it:a) cout<<it<<"";
        x++;
        y--;
        cout<<endl;
    }
}

int main() 
{
    int n;
    cin>>n;
    getNumberPattern(n);
    return 0;
}
