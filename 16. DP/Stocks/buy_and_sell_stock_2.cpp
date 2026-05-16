// Input:
// prices = [7,1,5,3,6,4]
// Output:
// 7
// Explanation:
// Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// Recursion
int findMax(int ind,int buy,int n,vector<int>& prices)
{
    if(ind==n)
        return 0;
    int profit=0;
    if(buy)
    {
        int pick=-prices[ind]+findMax(ind+1,0,n,prices);
        int notPick=findMax(ind+1,1,n,prices);
        profit=max(pick,notPick);
    }
    else
    {
        int pick=prices[ind]+findMax(ind+1,1,n,prices);
        int notPick=findMax(ind+1,0,n,prices);
        profit=max(pick,notPick);
    }
    return profit;
}

int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    return findMax(0,1,n,prices);
}

// Memoization
int findMax(int ind,int buy,int n,vector<int>& prices,vector<vector<int>>& dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    int profit=0;
    if(buy)
    {
        int pick=-prices[ind]+findMax(ind+1,0,n,prices,dp);
        int notPick=findMax(ind+1,1,n,prices,dp);
        profit=max(pick,notPick);
    }
    else
    {
        int pick=prices[ind]+findMax(ind+1,1,n,prices,dp);
        int notPick=findMax(ind+1,0,n,prices,dp);
        profit=max(pick,notPick);
    }
    return dp[ind][buy]=profit;
}

int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return findMax(0,1,n,prices,dp);
}

// Tabulation
int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j>=0;j--)
        {
            int profit=0;
            if(j)
            {
                int pick=-prices[i]+dp[i+1][0];
                int notPick=dp[i+1][1];
                profit=max(pick,notPick);
            }
            else
            {
                int pick=prices[i]+dp[i+1][1];
                int notPick=dp[i+1][0];
                profit=max(pick,notPick);
            }
            dp[i][j]=profit;
        }
    }
    return dp[0][1];
}

// Space Optimization
int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<int> next(2,0);
    next[0]=0;
    next[1]=0;
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(2,0);
        for(int j=1;j>=0;j--)
        {
            int profit=0;
            if(j)
            {
                int pick=-prices[i]+next[0];
                int notPick=next[1];
                profit=max(pick,notPick);
            }
            else
            {
                int pick=prices[i]+next[1];
                int notPick=next[0];
                profit=max(pick,notPick);
            }
            curr[j]=profit;
        }
        next=curr;
    }
    return next[1];
}
