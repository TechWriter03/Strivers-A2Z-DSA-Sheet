// Input:
// nums = [1,2,4,8]
// Output:
// [1,2,4,8]

vector<int> largestDivisibleSubset(vector<int>& nums)
{
    int n=nums.size(),len=1,last=0;
    sort(nums.begin(),nums.end());
    vector<int> dp(n,1);
    vector<int> parent(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        for(int j=0;j<i;j++)
        {
            if((nums[i]%nums[j])==0 && 1+dp[j]>dp[i])
            {
                dp[i]=1+dp[j];
                parent[i]=j;
            }
        }
        if(dp[i]>len)
        {
            len=dp[i];
            last=i;
        }
    }

    vector<int> ans;
    while(parent[last]!=last)
    {
        ans.push_back(nums[last]);
        last=parent[last];
    }
    ans.push_back(nums[last]);
    reverse(ans.begin(),ans.end());
    return ans;
}
