// Input:
// 2
// 3 5
// 2 3 5
// 3 1
// -1 1 1
// Output:
// 2
// 3
// Explanation:
// - For the first case:
// There are two subarrays with sum = 5, [2, 3] and [5]. 
// Hence the length of the longest subarray is 2.
// - For the second case:
// Longest subarray with sum = 1 is [1, -1, 1].

int getLongestSubarray(vector<int>& nums, int k)
{
    int n=nums.size(),preSum=0,maxLen=0;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        preSum+=nums[i];
        if(preSum==k)
            maxLen=max(maxLen,i+1);
        int rem=preSum-k;
        if(mp.find(rem)!=mp.end())
        {
            int Len=i-mp[rem];
            maxLen=max(maxLen,Len);
        }
        if(mp.find(preSum)==mp.end())
            mp[preSum]=i;
    }
    return maxLen;
}
