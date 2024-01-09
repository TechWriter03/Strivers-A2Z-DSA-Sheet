// Input: 
// nums = [1,2,3,4,5,6,7]
// k = 3
// Output: 
// [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

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
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
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
