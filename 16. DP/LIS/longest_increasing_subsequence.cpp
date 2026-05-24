// Input:
// nums = [10,9,2,5,3,7,101,18]
// Output:
// 4
// Explanation:
// The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Recursion
int LIS(int ind,int prev,int n,vector<int>& nums)
{
    if(ind==n)
        return 0;
    int pick=0;
    if(prev==-1 || nums[prev]<nums[ind])
        pick=1+LIS(ind+1,ind,n,nums);
    int notPick=LIS(ind+1,prev,n,nums);
    return max(pick,notPick);
}

int lengthOfLIS(vector<int>& nums)
{
    int n=nums.size();
    return LIS(0,-1,n,nums);
}

// Memoization
int LIS(int ind,int prev,int n,vector<int>& nums,vector<vector<int>>& dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][prev+1]!=-1)
        return dp[ind][prev+1];
    int pick=0;
    if(prev==-1 || nums[prev]<nums[ind])
        pick=1+LIS(ind+1,ind,n,nums,dp);
    int notPick=LIS(ind+1,prev,n,nums,dp);
    return dp[ind][prev+1]=max(pick,notPick);
}

int lengthOfLIS(vector<int>& nums)
{
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return LIS(0,-1,n,nums,dp);
}

// Tabulation
int lengthOfLIS(vector<int>& nums)
{
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=-1;j--)
        {
            int pick=0;
            if(j==-1 || nums[j]<nums[i])
                pick=1+dp[i+1][i+1];
            int notPick=dp[i+1][j+1];
            dp[i][j+1]=max(pick,notPick);
        }
    }
    return dp[0][0];
}

// Space Optimization
int lengthOfLIS(vector<int>& nums)
{
    int n=nums.size(),len=1;
    vector<int> dp(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
                dp[i]=max(1+dp[j],dp[i]);
        }
        len=max(dp[i],len);
    }
    return len;
}
