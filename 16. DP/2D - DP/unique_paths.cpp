// Input:
// m = 3, n = 7
// Output:
// 28

// MEMOIZATION
int paths(int m,int n,vector<vector<int>>& dp,int row,int col)
{
    if(row==m-1 && col==n-1)
        return 1;
    if(row>=m || col>=n)
        return 0;
    if(dp[row][col]!=-1)
        return dp[row][col];
    dp[row][col]=paths(m,n,dp,row,col+1)+paths(m,n,dp,row+1,col);
    return dp[row][col];
}

int uniquePaths(int m, int n)
{
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return paths(m,n,dp,0,0);
}

// TABULATION
int uniquePaths(int m, int n)
{
    vector<vector<int>>dp(m,vector<int>(n));
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
