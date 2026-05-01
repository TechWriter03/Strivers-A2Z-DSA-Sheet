// Input:
// s = "babgbag", t = "bag"
// Output:
// 5
// Explanation:
// There are 5 ways you can generate "bag" from s.

// Recursion
int countWays(int i,int j,int m,int n,string& s,string& t)
{
    if(j>=n)
        return 1;
    if(i>=m)
        return 0;
    if(s[i]==t[j])
        return countWays(i+1,j+1,m,n,s,t)+countWays(i+1,j,m,n,s,t);
    return countWays(i+1,j,m,n,s,t);
}

int numDistinct(string s,string t)
{
    int m=s.size(),n=t.size();
    return countWays(0,0,m,n,s,t);
}

// Memoization
int countWays(int i,int j,int m,int n,string& s,string& t,vector<vector<int>>& dp)
{
    if(j>=n)
        return 1;
    if(i>=m)
        return 0;
    if(s[i]==t[j])
        return dp[i][j]=countWays(i+1,j+1,m,n,s,t,dp)+countWays(i+1,j,m,n,s,t,dp);
    return dp[i][j]=countWays(i+1,j,m,n,s,t,dp);
}

int numDistinct(string s,string t)
{
    int m=s.size(),n=t.size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return countWays(0,0,m,n,s,t,dp);
}

// Tabulation
int numDistinct(string s,string t)
{
    int m=s.size(),n=t.size();
    vector<vector<unsigned int>> dp(m+1,vector<unsigned int>(n+1,0));
    for(int i=0;i<=m;i++)
    {
        dp[i][n]=1;
    }
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(s[i]==t[j])
                dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
            else
                dp[i][j]=dp[i+1][j];
        }
    }
    return dp[0][0];
}

// Space Optimization
int numDistinct(string s,string t)
{
    int m=s.size(),n=t.size();
    vector<unsigned int> dp(n+1,0);
    dp[n]=1;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i]==t[j])
                dp[j]=dp[j+1]+dp[j];
        }
    }
    return dp[0];
}
