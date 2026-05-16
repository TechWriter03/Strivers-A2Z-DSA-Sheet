// Input:
// prices = [1,2,3,0,2]
// Output:
// 3
// Explanation:
// transactions = [buy, sell, cooldown, buy, sell]

// Recursion
int findMax(int ind,int buy,int n,vector<int>& prices)
{
    if(ind>=n)
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
        int pick=prices[ind]+findMax(ind+2,1,n,prices);
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
int findMax(int ind,int buy,int n,int fee,vector<int>& prices,vector<vector<int>>& dp)
{
    if(ind==n)
        return 0;
    int profit=0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    if(buy)
    {
        int pick=-prices[ind]+findMax(ind+1,0,n,fee,prices,dp);
        int notPick=findMax(ind+1,1,n,fee,prices,dp);
        profit=max(pick,notPick);
    }
    else
    {
        int pick=prices[ind]-fee+findMax(ind+1,1,n,fee,prices,dp);
        int notPick=findMax(ind+1,0,n,fee,prices,dp);
        profit=max(pick,notPick);
    }
    return dp[ind][buy]=profit;
}

int maxProfit(vector<int>& prices,int fee)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    return findMax(0,1,n,fee,prices,dp);
}

// Tabulation
int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
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
                int pick=prices[i]+dp[i+2][1];
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
    vector<int> next1(2,0);
    vector<int> next2(2,0);
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(2,0);
        for(int j=1;j>=0;j--)
        {
            int profit=0;
            if(j)
            {
                int pick=-prices[i]+next1[0];
                int notPick=next1[1];
                profit=max(pick,notPick);
            }
            else
            {
                int pick=prices[i]+next2[1];
                int notPick=next1[0];
                profit=max(pick,notPick);
            }
            curr[j]=profit;
        }
        next2=next1;
        next1=curr;
    }
    return next1[1];
}
