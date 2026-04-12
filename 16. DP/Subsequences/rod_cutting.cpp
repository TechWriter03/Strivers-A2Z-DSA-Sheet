// Input:
// price[] = [1, 5, 8, 9, 10, 17, 17, 20]
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.

// Recursion
int maxPrice(int ind,int curr,int n,vector<int>& price)
{
    if(ind==n)
        return 0;
    int notPick=maxPrice(ind+1,curr,n,price);
    int pick=INT_MIN;
    int len=ind+1;
    if(curr+len<=n)
        pick=price[ind]+maxPrice(ind,curr+len,n,price);
    return max(pick,notPick);
}

int cutRod(vector<int>& price)
{
    int n=price.size();
    return maxPrice(0,0,n,price);
}

// Memoization
int maxPrice(int ind,int curr,int n,vector<int>& price,vector<vector<int>>& dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][curr]!=-1)
        return dp[ind][curr];
    int notPick=maxPrice(ind+1,curr,n,price,dp);
    int pick=INT_MIN;
    int len=ind+1;
    if(curr+len<=n)
        pick=price[ind]+maxPrice(ind,curr+len,n,price,dp);
    return dp[ind][curr]=max(pick,notPick);
}

int cutRod(vector<int>& price)
{
    int n=price.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return maxPrice(0,0,n,price,dp);
}

// Tabulation
int cutRod(vector<int>& price)
{
    int n=price.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n;j>=0;j--)
        {
            int notPick=dp[i+1][j];
            int pick=INT_MIN;
            int len=i+1;
            if(j+len<=n)
                pick=price[i]+dp[i][j+len];
            dp[i][j]=max(pick,notPick);
        }
    }
    return dp[0][0];
}

// Space Optimization
int cutRod(vector<int>& price)
{
    int n=price.size();
    vector<int> next(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(n+1,0);
        for(int j=n;j>=0;j--)
        {
            int notPick=next[j];
            int pick=INT_MIN;
            int len=i+1;
            if(j+len<=n)
                pick=price[i]+curr[j+len];
            curr[j]=max(pick,notPick);
        }
        next=curr;
    }
    return next[0];
}
