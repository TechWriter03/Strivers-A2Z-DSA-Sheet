// Input:
// arr = [5, 2, 3, 10, 6, 8], target = 10
// Output:
// 3
// Explanation:
// The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

// Recursion
int findWays(int ind,int sum,int n,int target,vector<int>& arr)
{
    if(ind==n)
        return (sum==target);
    if(sum>target)
        return 0;
    int pick=findWays(ind+1,sum+arr[ind],n,target,arr);
    int notPick=findWays(ind+1,sum,n,target,arr);
    return pick+notPick;
}

int perfectSum(vector<int>& arr,int target)
{
    int n=arr.size();
    return findWays(0,0,n,target,arr);
}

// Memoization
int findWays(int ind,int sum,int n,int target,vector<int>& arr,vector<vector<int>>& dp)
{
    if(ind==n)
        return (sum==target);
    if(sum>target)
        return 0;
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    int pick=findWays(ind+1,sum+arr[ind],n,target,arr,dp);
    int notPick=findWays(ind+1,sum,n,target,arr,dp);
    return dp[ind][sum]=pick+notPick;
}

int perfectSum(vector<int>& arr,int target)
{
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    return findWays(0,0,n,target,arr,dp);
}

// Tabulation
int perfectSum(vector<int>& arr,int target)
{
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[n][target]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=target;j>=0;j--)
        {
            int pick=0;
            if(j+arr[i]<=target)
                pick=dp[i+1][j+arr[i]];
            int notPick=dp[i+1][j];
            dp[i][j]=pick+notPick;
        }
    }
    return dp[0][0];
}

// Space Optimization
int perfectSum(vector<int>& arr,int target)
{
    int n=arr.size();
    vector<int> next(target+1,0);
    next[target]=1;
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(target+1,0);
        for(int j=target;j>=0;j--)
        {
            int pick=0;
            if(j+arr[i]<=target)
                pick=next[j+arr[i]];
            int notPick=next[j];
            curr[j]=pick+notPick;
        }
        next=curr;
    }
    return next[0];
}
