// Input:
// k = 2, prices = [2,4,1]
// Output:
// 2
// Explanation:
// Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

// Recursion
int findMax(int ind,int txn,int n,int k,vector<int>& prices)
{
    if(ind==n || txn==2*k)
        return 0;
    int profit=0;
    if(txn%2==0)
    {
        int buy=-prices[ind]+findMax(ind+1,txn+1,n,k,prices);
        int notBuy=findMax(ind+1,txn,n,k,prices);
        profit=max(buy,notBuy);
    }
    else
    {
        int sell=prices[ind]+findMax(ind+1,txn+1,n,k,prices);
        int notSell=findMax(ind+1,txn,n,k,prices);
        profit=max(sell,notSell);
    }
    return profit;
}

int maxProfit(int k,vector<int>& prices)
{
    int n=prices.size();
    return findMax(0,0,n,k,prices);
}

// Memoization
int findMax(int ind,int txn,int n,int k,vector<int>& prices,vector<vector<int>>& dp)
{
    if(ind==n || txn==2*k)
        return 0;
    if(dp[ind][txn]!=-1)
        return dp[ind][txn];
    int profit=0;
    if(txn%2==0)
    {
        int buy=-prices[ind]+findMax(ind+1,txn+1,n,k,prices,dp);
        int notBuy=findMax(ind+1,txn,n,k,prices,dp);
        profit=max(buy,notBuy);
    }
    else
    {
        int sell=prices[ind]+findMax(ind+1,txn+1,n,k,prices,dp);
        int notSell=findMax(ind+1,txn,n,k,prices,dp);
        profit=max(sell,notSell);
    }
    return dp[ind][txn]=profit;
}

int maxProfit(int k,vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
    return findMax(0,0,n,k,prices,dp);
}

// Tabulation
int maxProfit(int k,vector<int>& prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=2*k-1;j>=0;j--)
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
int maxProfit(int k,vector<int>& prices)
{
    int n=prices.size();
    vector<int> next(2*k+1,0);
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(2*k+1,0);
        for(int j=2*k-1;j>=0;j--)
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
