// Input
// W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
// Output:
// 3
// Explanation:
// Choose the last item, which weighs 1 unit and has a value of 3.

// Recursion
int findMax(int ind,int curr,int n,int W,vector<int>& val,vector<int>& wt)
{
    if(ind==n)
        return 0;
    int notPick=findMax(ind+1,curr,n,W,val,wt);
    int pick=INT_MIN;
    if(curr+wt[ind]<=W)
        pick=val[ind]+findMax(ind+1,curr+wt[ind],n,W,val,wt);
    return max(pick,notPick);
}

int knapsack(int W,vector<int>& val,vector<int>& wt)
{
    int n=val.size();
    return findMax(0,0,n,W,val,wt);
}

// Memoization
int findMax(int ind,int curr,int n,int W,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][curr]!=-1)
        return dp[ind][curr];
    int notPick=findMax(ind+1,curr,n,W,val,wt,dp);
    int pick=INT_MIN;
    if(curr+wt[ind]<=W)
        pick=val[ind]+findMax(ind+1,curr+wt[ind],n,W,val,wt,dp);
    return dp[ind][curr]=max(pick,notPick);
}

int knapsack(int W,vector<int>& val,vector<int>& wt)
{
    int n=val.size();
    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
    return findMax(0,0,n,W,val,wt,dp);
}

// Tabulation
int knapsack(int W,vector<int>& val,vector<int>& wt)
{
    int n=val.size();
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=W;j>=0;j--)
        {
            int notPick=dp[i+1][j];
            int pick=INT_MIN;
            if(j+wt[i]<=W)
                pick=val[i]+dp[i+1][j+wt[i]];
            dp[i][j]=max(pick,notPick);
        }
    }
    return dp[0][0];
}

// Space Optimization
int knapsack(int W,vector<int>& val,vector<int>& wt)
{
    int n=val.size();
    vector<int> next(W+1,0);
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(W+1,0);
        for(int j=W;j>=0;j--)
        {
            int notPick=next[j];
            int pick=INT_MIN;
            if(j+wt[i]<=W)
                pick=val[i]+next[j+wt[i]];
            curr[j]=max(pick,notPick);
        }
        next=curr;
    }
    return next[0];
}
