// Input:
// word1 = "horse", word2 = "ros"
// Output:
// 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// Recursion
int findMin(int i,int j,int m,int n,string& s1,string& s2)
{
    if(i>=m)
        return n-j;
    if(j>=n)
        return m-i;
    if(s1[i]==s2[j])
        return findMin(i+1,j+1,m,n,s1,s2);
    int insert=1+findMin(i,j+1,m,n,s1,s2);
    int del=1+findMin(i+1,j,m,n,s1,s2);
    int replace=1+findMin(i+1,j+1,m,n,s1,s2);
    return min({insert,del,replace});
}

int minDistance(string s1,string s2)
{
    int m=s1.size(),n=s2.size();
    return findMin(0,0,m,n,s1,s2);
}

// Memoization
int findMin(int i,int j,int m,int n,string& s1,string& s2,vector<vector<int>>& dp)
{
    if(i>=m)
        return n-j;
    if(j>=n)
        return m-i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]==s2[j])
        return dp[i][j]=findMin(i+1,j+1,m,n,s1,s2,dp);
    int insert=findMin(i,j+1,m,n,s1,s2,dp);
    int del=findMin(i+1,j,m,n,s1,s2,dp);
    int replace=findMin(i+1,j+1,m,n,s1,s2,dp);
    return dp[i][j]=1+min({insert,del,replace});
}

int minDistance(string s1,string s2)
{
    int m=s1.size(),n=s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return findMin(0,0,m,n,s1,s2,dp);
}

// Tabulation
int minDistance(string s1,string s2)
{
    int m=s1.size(),n=s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++)
    {
        dp[i][n]=m-i;
    }
    for(int j=0;j<=n;j++)
    {
        dp[m][j]=n-j;
    }
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(s1[i]==s2[j])
                dp[i][j]=dp[i+1][j+1];
            else
                dp[i][j]=1+min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]});
        }
    }
    return dp[0][0];
}

// Space Optimization
int minDistance(string s1,string s2)
{
    int m=s1.size(),n=s2.size();
    vector<int> next(n+1,0);
    for(int j=0;j<=n;j++)
    {
        next[j]=n-j;
    }
    for(int i=m-1;i>=0;i--)
    {
        vector<int> curr(n+1,0);
        curr[n]=m-i;
        for(int j=n-1;j>=0;j--)
        {
            if(s1[i]==s2[j])
                curr[j]=next[j+1];
            else
                curr[j]=1+min({curr[j+1],next[j],next[j+1]});
        }
        next=curr;
    }
    return next[0];
}
