// Input:
// heights[] = [20, 30, 40, 20]
// Output:
// 20
// Explanation:
// Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
// jump from stair 0 to 1: cost = |30 - 20| = 10
// jump from stair 1 to 3: cost = |20 - 30| = 10
// Total Cost = 10 + 10 = 20

// Recusion
int findMin(int ind,vector<int>& height)
{
    if(ind==0)
        return 0;    
    int jump1=findMin(ind-1,height)+abs(height[ind]-height[ind-1]);
    int jump2=INT_MAX;
    if(ind>1)
        jump2=findMin(ind-2,height)+abs(height[ind]-height[ind-2]);
    return min(jump1,jump2);
}
int minCost(vector<int>& height)
{
    int n=height.size();
    return findMin(n-1,height);
}

// Memoization
int findMin(int ind,vector<int>& height,vector<int>& dp)
{
    if(ind==0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int jump1=findMin(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
    int jump2=INT_MAX;
    if(ind>1)
        jump2=findMin(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
    return dp[ind]=min(jump1,jump2);
}
int minCost(vector<int>& height)
{
    int n=height.size();
    vector<int> dp(n,-1);
    return findMin(n-1,height,dp);
}

// Tabulation
int minCost(vector<int>& height)
{
    int n=height.size();
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int jump1=dp[i-1]+abs(height[i]-height[i-1]);
        int jump2=INT_MAX;
        if(i>1)
            jump2=dp[i-2]+abs(height[i]-height[i-2]);
        dp[i]=min(jump1,jump2);
    }
    return dp[n-1];
}

// Space Optimization
int minCost(vector<int>& height)
{
    int n=height.size();
    int prev1=0,prev2=0;
    for(int i=1;i<n;i++)
    {
        int jump1=prev1+abs(height[i]-height[i-1]);
        int jump2=INT_MAX;
        if(i>1)
            jump2=prev2+abs(height[i]-height[i-2]);
        int curr=min(jump1,jump2);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
