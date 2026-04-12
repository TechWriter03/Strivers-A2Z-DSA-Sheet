// Input: 
// coins = [1,2,5], amount = 11
// Output:
// 3
// Explanation:
// 11 = 5 + 5 + 1

// Recursion
int findMin(int ind,long long sum,int n,int amount,vector<int>& coins)
{
    if(sum==amount)
        return 0;
    if(ind==n)
        return 1e9;
    int notPick=findMin(ind+1,sum,n,amount,coins);
    int pick=1e9;
    if(sum+coins[ind]<=amount)
        pick=1+findMin(ind,sum+coins[ind],n,amount,coins);
    return min(pick,notPick);
}

int coinChange(vector<int>& coins,int amount)
{
    int n=coins.size();
    int minCoins=findMin(0,0,n,amount,coins);
    if(minCoins>=1e9)
        return -1;
    return minCoins;
}

// Memoization
int findMin(int ind,long long sum,int n,int amount,vector<int>& coins,vector<vector<long long>>& dp)
{
    if(sum==amount)
        return 0;
    if(ind==n)
        return 1e9;
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    int notPick=findMin(ind+1,sum,n,amount,coins,dp);
    int pick=1e9;
    if(sum+coins[ind]<=amount)
        pick=1+findMin(ind,sum+coins[ind],n,amount,coins,dp);
    return dp[ind][sum]=min(pick,notPick);
}

int coinChange(vector<int>& coins,int amount)
{
    int n=coins.size();
    vector<vector<long long>> dp(n+1,vector<long long>(amount+1,-1));
    int minCoins=findMin(0,0,n,amount,coins,dp);
    if(minCoins>=1e9)
        return -1;
    return minCoins;
}

// Tabulation
int coinChange(vector<int>& coins,int amount)
{
    int n=coins.size();
    vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
    dp[n][amount]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=amount;j>=0;j--)
        {
            int notPick=dp[i+1][j];
            int pick=1e9;
            if((long long)j+coins[i]<=amount)
                pick=1+dp[i][j+coins[i]];
            dp[i][j]=min(pick,notPick);
        }
    }
    int minCoins=dp[0][0];
    if(minCoins>=1e9)
        return -1;
    return minCoins;
}

// Space Optimization
int coinChange(vector<int>& coins,int amount)
{
    int n=coins.size();
    vector<int> next(amount+1,1e9);
    next[amount]=0;
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(amount+1,1e9);
        for(int j=amount;j>=0;j--)
        {
            int notPick=next[j];
            int pick=1e9;
            if((long long)j+coins[i]<=amount)
                pick=1+curr[j+coins[i]];
            curr[j]=min(pick,notPick);
        }
        next=curr;
    }
    int minCoins=next[0];
    if(minCoins>=1e9)
        return -1;
    return minCoins;
}
