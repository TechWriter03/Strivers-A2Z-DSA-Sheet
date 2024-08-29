// Input:
// grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output:
// 7
// Explanation:
// Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

int minPath(int m,int n,vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp)
{
    if(row==m-1 && col==n-1) 
        return grid[row][col];
    if(row>=m || col>=n) 
        return INT_MAX;
    if(dp[row][col]!=-1) 
        return dp[row][col];
    return dp[row][col]=grid[row][col]+min(minPath(m,n,grid,row,col+1,dp),minPath(m,n,grid,row+1,col,dp));
}

int minPathSum(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return minPath(m,n,grid,0,0,dp);
}
