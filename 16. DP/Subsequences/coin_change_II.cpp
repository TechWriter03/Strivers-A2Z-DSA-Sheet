// Input:
// amount = 5, coins = [1,2,5]
// Output:
// 4
// Explanation:
// there are four ways to make up the amount.
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

// Recursion
int countWays(int ind,int sum,int n,int amount,vector<int>& coins)
{
    if(sum==amount)
        return 1;
    if(ind==n)
        return (sum==amount);
    int notPick=countWays(ind+1,sum,n,amount,coins);
    int pick=0;
    if(sum+coins[ind]<=amount)
        pick=countWays(ind,sum+coins[ind],n,amount,coins);
    return pick+notPick;
}

int change(int amount,vector<int>& coins)
{
    int n=coins.size();
    return countWays(0,0,n,amount,coins);
}

// Memoization
int countWays(int ind,int sum,int n,int amount,vector<int>& coins,vector<vector<int>>& dp)
{
    if(sum==amount)
        return 1;
    if(ind==n)
        return (sum==amount);
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    int notPick=countWays(ind+1,sum,n,amount,coins,dp);
    int pick=0;
    if(sum+coins[ind]<=amount)
        pick=countWays(ind,sum+coins[ind],n,amount,coins,dp);
    return dp[ind][sum]=pick+notPick;
}

int change(int amount,vector<int>& coins)
{
    int n=coins.size();
    vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
    return countWays(0,0,n,amount,coins,dp);
}

// Tabulation
int change(int amount,vector<int>& coins)
{
    int n=coins.size();
    vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(amount+1,0));
    dp[n][amount]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=amount;j>=0;j--)
        {
            unsigned long long notPick=dp[i+1][j];
            unsigned long long pick=0;
            if(j+coins[i]<=amount)
                pick=dp[i][j+coins[i]];
            dp[i][j]=(pick+notPick);
        }
    }
    return dp[0][0];
}

// Space Optimization
int change(int amount,vector<int>& coins)
{
    int n=coins.size();
    vector<unsigned long long> next(amount+1,0);
    next[amount]=1;
    for(int i=n-1;i>=0;i--)
    {
        vector<unsigned long long> curr(amount+1,0);
        for(int j=amount;j>=0;j--)
        {
            unsigned long long notPick=next[j];
            unsigned long long pick=0;
            if(j+coins[i]<=amount)
                pick=curr[j+coins[i]];
            curr[j]=(pick+notPick);
        }
        next=curr;
    }
    return next[0];
}
