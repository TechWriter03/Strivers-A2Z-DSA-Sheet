// Input:
// grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// Output:
// 12
// Explanation:
// The minimum falling path is 1 → 4 → 7, with sum 12.

// Recursion
int minPath(int row,int col,int n,vector<vector<int>>& grid)
{
    if(col<0 || col>=n)
        return INT_MAX;
    if(row==n-1)
        return grid[row][col];
    int down=minPath(row+1,col,n,grid);
    int leftDown=minPath(row+1,col-1,n,grid);
    int rightDown=minPath(row+1,col+1,n,grid);
    return grid[row][col]+min({down,leftDown,rightDown});
}

int minFallingPathSum(vector<vector<int>>& grid)
{
    int n=grid.size(),minSum=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int sum=minPath(0,i,n,grid);
        minSum=min(sum,minSum);
    }
    return minSum;
}

// Memoization
int minPath(int row,int col,int n,vector<vector<int>>& grid,vector<vector<int>>& dp)
{
    if(col<0 || col>=n)
        return INT_MAX;
    if(row==n-1)
        return grid[row][col];
    if(dp[row][col]!=-1)
        return dp[row][col];
    int down=minPath(row+1,col,n,grid,dp);
    int leftDown=minPath(row+1,col-1,n,grid,dp);
    int rightDown=minPath(row+1,col+1,n,grid,dp);
    return dp[row][col]=grid[row][col]+min({down,leftDown,rightDown});
}

int minFallingPathSum(vector<vector<int>>& grid)
{
    int n=grid.size(),minSum=INT_MAX;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        int sum=minPath(0,i,n,grid,dp);
        minSum=min(sum,minSum);
    }
    return minSum;
}

// Tabulation
int minFallingPathSum(vector<vector<int>>& grid)
{
    int n=grid.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        dp[n-1][i]=grid[n-1][i];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            int down=dp[i+1][j];
            int leftDown=(j-1>=0)?dp[i+1][j-1]:INT_MAX;
            int rightDown=(j+1<n)?dp[i+1][j+1]:INT_MAX;
            dp[i][j]=grid[i][j]+min({down,leftDown,rightDown});
        }
    }
    int minSum=INT_MAX;
    for(int i=0;i<n;i++)
    {
        minSum=min(dp[0][i],minSum);
    }
    return minSum;
}

// Space Optimization
int minFallingPathSum(vector<vector<int>>& grid)
{
    int n=grid.size();
    vector<int> next(n,0);
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(n,0);
        for(int j=n-1;j>=0;j--)
        {
            if(i==n-1)
            {
                curr[j]=grid[i][j];
            }
            else
            {
                int down=next[j];
                int leftDown=(j-1>=0)?next[j-1]:INT_MAX;
                int rightDown=(j+1<n)?next[j+1]:INT_MAX;
                curr[j]=grid[i][j]+min({down,leftDown,rightDown});
            }
        }
        next=curr;
    }
    int minSum=INT_MAX;
    for(int i=0;i<n;i++)
    {
        minSum=min(next[i],minSum);
    }
    return minSum;
}
