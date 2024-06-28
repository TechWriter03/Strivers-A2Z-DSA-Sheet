// Input: 
// n = 3
// Output: 
// 3
// Explanation: 
// There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Recursion
int climbStairs(int n) 
{
    if(n==0) return 1;
    if(n<0) return 0;
    return climbStairs(n-1)+climbStairs(n-2);
}

// Memoization
int findWays(int n,vector<int>& dp)
{
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=findWays(n-1,dp)+findWays(n-2,dp);
}
int climbStairs(int n) 
{
    vector<int>dp(n+1,-1);
    dp[0]=1;
    return findWays(n,dp);
}

// Tabulation
int climbStairs(int n) 
{
    vector<int>dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

// Space Optimization
int climbStairs(int n) 
{
    int prev1=1,prev2=1,curr;
    for(int i=2;i<=n;i++)
    {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
