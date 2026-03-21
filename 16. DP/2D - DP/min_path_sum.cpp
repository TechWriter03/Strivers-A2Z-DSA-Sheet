// Input:
// grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output:
// 7
// Explanation:
// Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Recursion
int findMin(int row,int col,int m,int n,vector<vector<int>>& grid)
{
    if(row==m-1 && col==n-1)
        return grid[row][col];
    if(row>=m || col>=n)
        return INT_MAX;
    int right=findMin(row,col+1,m,n,grid);
    int down=findMin(row+1,col,m,n,grid);
    return grid[row][col]+min(right,down);
}

int minPathSum(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    return findMin(0,0,m,n,grid);
}

// Memoization
int findMin(int row,int col,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp)
{
    if(row==m-1 && col==n-1)
        return grid[row][col];
    if(row>=m || col>=n)
        return INT_MAX;
    if(dp[row][col]!=-1)
        return dp[row][col];
    int right=findMin(row,col+1,m,n,grid,dp);
    int down=findMin(row+1,col,m,n,grid,dp);
    return dp[row][col]=grid[row][col]+min(right,down);
}

int minPathSum(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return findMin(0,0,m,n,grid,dp);
}

// Taulation
int minPathSum(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[m-1][n-1]=grid[m-1][n-1];
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(i==m-1 && j==n-1)
                continue;
            int right=(j+1<n)?dp[i][j+1]:INT_MAX;
            int down=(i+1<m)?dp[i+1][j]:INT_MAX;
            dp[i][j]=grid[i][j]+min(right,down);
        }
    }
    return dp[0][0];
}

// Space Optimization
int minPathSum(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    vector<int> next(n,0);
    for(int i=m-1;i>=0;i--)
    {
        vector<int> curr(n,0);
        for(int j=n-1;j>=0;j--)
        {
            if(i==m-1 && j==n-1)
            {
                curr[j]=grid[i][j];
            }
            else
            {
                int right=(j+1<n)?curr[j+1]:INT_MAX;
                int down=(i+1<m)?next[j]:INT_MAX;
                curr[j]=grid[i][j]+min(right,down);
            }
        }
        next=curr;
    }
    return next[0];
}
