// Input:
// coins = [1,2,5], amount = 11
// Output:
// 3
// Explanation:
// 11 = 5 + 5 + 1

int minCoins(vector<int>& coins,int n,int ind,int curr,int amt,vector<vector<int>>& dp)
{
    if(curr==amt)
        return 0;
    if(ind>=n || curr>amt)
        return 1e9;
    if(dp[ind][curr]!=-1)
        return dp[ind][curr];
    int pick=INT_MAX;
    if(coins[ind]<=amt)
        pick=1+minCoins(coins,n,ind,curr+coins[ind],amt,dp);
    int notPick=0+minCoins(coins,n,ind+1,curr,amt,dp);
    return dp[ind][curr]=min(pick,notPick);
}
int coinChange(vector<int>& coins, int amt)
{
    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(amt+1,-1));
    int ans=minCoins(coins,n,0,0,amt,dp);
    return (ans>=1e9)?-1:ans;
}
