// Input: 
// nums = [1,1,0,1,1,1]
// Output: 
// 3
// Explanation: 
// The first two digits or the last three digits are consecutive 1s. 
// The maximum number of consecutive 1s is 3.

#include <bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) 
{
    int count=0,max=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==1)
            count++;
        else
            count=0;
        if(count>max)
            max=count;
    }
    return max;
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
    cout<<findMaxConsecutiveOnes(v);
    return 0;
}
