// Input:
// nums = [1,2,3,1]
// Output:
// 4
// Explanation:
// Rob house 1 (money = 1) and then rob house 3 (money = 3).Total amount you can rob = 1 + 3 = 4.

// Recursion
int findMax(int ind,vector<int>& nums)
{
    if(ind==0)
        return nums[0];
    if(ind<0)
        return 0;
    int take=nums[ind]+findMax(ind-2,nums);
    int notTake=findMax(ind-1,nums);
    return max(take,notTake);
}

int rob(vector<int>& nums)
{
    int n=nums.size();
    return findMax(n-1,nums);
}

// Memoization
int findMax(int ind,vector<int>& nums,vector<int>& dp)
{
    if(ind==0)
        return nums[0];
    if(ind<0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int take=nums[ind]+findMax(ind-2,nums,dp);
    int notTake=findMax(ind-1,nums,dp);
    return dp[ind]=max(take,notTake);
}

int rob(vector<int>& nums)
{
    int n=nums.size();
    vector<int> dp(n,-1);
    return findMax(n-1,nums,dp);
}

// Tabulation
int rob(vector<int>& nums)
{
    int n=nums.size();
    if(n==1)
        return nums[0];
    vector<int> dp(n,-1);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++)
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
    return dp[n-1];
}

// Space Optimization
int rob(vector<int>& nums)
{
    int n=nums.size();
    if(n==1)
        return nums[0];
    int prev2=nums[0];
    int prev1=max(nums[0],nums[1]);
    for(int i=2;i<n;i++)
    {
        int curr=max(nums[i]+prev2,prev1);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}