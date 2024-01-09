// Input:
// n = 5
// arr = [1, 2, 3, 4, 5]
// Output: 
// [2, 3, 4, 5, 1]

#include <bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int>& arr, int n) 
{
    arr.push_back(arr[0]);
    arr.erase(arr.begin());
    return arr;
}

int main() 
{
    int n,ip;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>ip;
        v.push_back(ip);
    }
    vector<int>ans=rotateArray(v,n);
    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}
