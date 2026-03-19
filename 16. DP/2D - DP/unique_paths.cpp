// Input:
// m = 3, n = 7
// Output:
// 28

// Recursion
int countPaths(int row,int col,int m,int n)
{
    if(row==m-1 && col==n-1)
        return 1;
    if(row>=m || col>=n)
        return 0;
    int right=countPaths(row,col+1,m,n);
    int down=countPaths(row+1,col,m,n);
    return right+down;
}

int uniquePaths(int m,int n)
{
    return countPaths(0,0,m,n);
}

// Memoization
int countPaths(int row,int col,int m,int n,vector<vector<int>>& dp)
{
    if(row==m-1 && col==n-1)
        return 1;
    if(row>=m || col>=n)
        return 0;
    if(dp[row][col]!=-1)
        return dp[row][col];
    int right=countPaths(row,col+1,m,n,dp);
    int down=countPaths(row+1,col,m,n,dp);
    return dp[row][col]=right+down;
}

int uniquePaths(int m,int n)
{
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return countPaths(0,0,m,n,dp);
}

// Tabulation
int uniquePaths(int m,int n)
{
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[m-1][n-1]=1;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(i==m-1 && j==n-1)
                continue;
            int right=(j+1<n)?dp[i][j+1]:0;
            int down=(i+1<m)?dp[i+1][j]:0;
            dp[i][j]=right+down;
        }
    }
    return dp[0][0];
}

// Space Optimization
int uniquePaths(int m,int n)
{
    vector<int> next(n,0);
    for(int i=m-1;i>=0;i--)
    {
        vector<int> curr(n,0);
        for(int j=n-1;j>=0;j--)
        {
            if(i==m-1 && j==n-1)
            {
                curr[j]=1;
            }
            else
            {
                int right=(j+1<n)?curr[j+1]:0;
                int down=(i+1<m)?next[j]:0;
                curr[j]=right+down;
            }
        }
        next=curr;
    }
    return next[0];
}
