// Input: 
// ‘n’ = 5
// ‘a’ = [1, 2, 3, 4, 5]
// Output: 
// 1
// The given array is sorted in non-decreasing order; hence the answer will be 1.

#include <bits/stdc++.h>
using namespace std;
int isSorted(int n, vector<int> a) 
{
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
            return 0;
    }
    return 1;
}
int main() 
{
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int ip;
        cin>>ip;
        a.push_back(ip);
    }
    cout<<isSorted(n,a);
    return 0;
}
