// Input:
// prices = [3,3,5,0,0,3,1,4]
// Output:
// 6
// Explanation:
// Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

// Recursion
int findMax(int ind,int txn,int n,vector<int>& prices)
{
    if(ind==n || txn==4)
        return 0;
    int profit=0;
    if(txn%2==0)
    {
        int buy=-prices[ind]+findMax(ind+1,txn+1,n,prices);
        int notBuy=findMax(ind+1,txn,n,prices);
        profit=max(buy,notBuy);
    }
    else
    {
        int sell=prices[ind]+findMax(ind+1,txn+1,n,prices);
        int notSell=findMax(ind+1,txn,n,prices);
        profit=max(sell,notSell);
    }
    return profit;
}

int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    return findMax(0,0,n,prices);
}

// Memoization
int findMax(int ind,int txn,int n,vector<int>& prices,vector<vector<int>>& dp)
{
    if(ind==n || txn==4)
        return 0;
    if(dp[ind][txn]!=-1)
        return dp[ind][txn];
    int profit=0;
    if(txn%2==0)
    {
        int buy=-prices[ind]+findMax(ind+1,txn+1,n,prices,dp);
        int notBuy=findMax(ind+1,txn,n,prices,dp);
        profit=max(buy,notBuy);
    }
    else
    {
        int sell=prices[ind]+findMax(ind+1,txn+1,n,prices,dp);
        int notSell=findMax(ind+1,txn,n,prices,dp);
        profit=max(sell,notSell);
    }
    return dp[ind][txn]=profit;
}

int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(5,-1));
    return findMax(0,0,n,prices,dp);
}

// Tabulation
int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(5,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=3;j>=0;j--)
        {
            int profit=0;
            if(j%2==0)
            {
                int buy=-prices[i]+dp[i+1][j+1];
                int notBuy=dp[i+1][j];
                profit=max(buy,notBuy);
            }
            else
            {
                int sell=prices[i]+dp[i+1][j+1];
                int notSell=dp[i+1][j];
                profit=max(sell,notSell);
            }
            dp[i][j]=profit;
        }
    }
    return dp[0][0];
}

// Space Optimization
int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<int> next(5,0);
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(5,0);
        for(int j=3;j>=0;j--)
        {
            int profit=0;
            if(j%2==0)
            {
                int buy=-prices[i]+next[j+1];
                int notBuy=next[j];
                profit=max(buy,notBuy);
            }
            else
            {
                int sell=prices[i]+next[j+1];
                int notSell=next[j];
                profit=max(sell,notSell);
            }
            curr[j]=profit;
        }
        next=curr;
    }
    return next[0];
}
