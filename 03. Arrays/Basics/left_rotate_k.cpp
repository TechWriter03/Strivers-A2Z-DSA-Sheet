// Input:
// 4
// 5 6 7 8
// 3
// Output:
// 8 5 6 7
// Explanation:
// Rotate 1 steps to the left: 6 7 8 5
// Rotate 2 steps to the left: 7 8 5 6
// Rotate 2 steps to the left: 8 5 6 7

#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int>& nums,int i,int j)
{
    while(i<j)
    {
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}
vector<int> rotateArray(vector<int>arr, int k) 
{
    int n=arr.size();
    k%=n;
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
    return arr;
}
int main() 
{
    int n,k,ip;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>ip;
        v.push_back(ip);
    }
    cin>>k;
    vector<int>ans=rotateArray(v,k);
    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}
