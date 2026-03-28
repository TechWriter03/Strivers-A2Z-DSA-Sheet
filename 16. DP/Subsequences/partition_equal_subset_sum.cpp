// Input:
// nums = [1,5,11,5]
// Output:
// true
// Explanation:
// The array can be partitioned as [1, 5, 5] and [11].

// Recursion
bool subset(int ind,int sum,int n,int target,vector<int>& nums)
{
    if(sum==target)
        return true;
    if(ind>=n)
        return false;
    if(sum>target)
        return false;
    bool pick=subset(ind+1,sum+nums[ind],n,target,nums);
    bool notPick=subset(ind+1,sum,n,target,nums);
    return (pick || notPick);
}

bool canPartition(vector<int>& nums)
{
    int n=nums.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=nums[i];
    }
    if(total%2==1)
        return false;
    return subset(0,0,n,total/2,nums);
}


// Memoization
bool subset(int ind,int sum,int n,int target,vector<int>& nums,vector<vector<int>>& dp)
{
    if(sum==target)
        return true;
    if(ind>=n)
        return false;
    if(sum>target)
        return false;
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    bool pick=subset(ind+1,sum+nums[ind],n,target,nums,dp);
    bool notPick=subset(ind+1,sum,n,target,nums,dp);
    return dp[ind][sum]=(pick || notPick);
}

bool canPartition(vector<int>& nums)
{
    int n=nums.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=nums[i];
    }
    if(total%2==1)
        return false;
    int target=total/2;
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    return subset(0,0,n,target,nums,dp);
}

// Tabulation
bool canPartition(vector<int>& nums)
{
    int n=nums.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=nums[i];
    }
    if(total%2==1)
        return false;

    int target=total/2;
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    for(int i=0;i<=n;i++)
    {
        dp[i][target]=true;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=target;j>=0;j--)
        {
            bool notPick=dp[i+1][j];
            bool pick=false;
            if(j+nums[i]<=target)
                pick=dp[i+1][j+nums[i]];
            dp[i][j]=(pick || notPick);
        }
    }
    return dp[0][0];
}

// Space Optimization
bool canPartition(vector<int>& nums)
{
    int n=nums.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=nums[i];
    }
    if(total%2==1)
        return false;

    int target=total/2;
    vector<bool> next(target+1,false);
    next[target]=true;
    for(int i=n-1;i>=0;i--)
    {
        vector<bool> curr(target+1,false);
        for(int j=target;j>=0;j--)
        {
            bool notPick=next[j];
            bool pick=false;
            if(j+nums[i]<=target)
                pick=next[j+nums[i]];
            curr[j]=(pick || notPick);
        }
        next=curr;
    }
    return next[0];
}
