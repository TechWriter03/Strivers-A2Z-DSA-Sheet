// Input:
// grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output:
// 3
// Explanation:
// There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis)
{
    vis[row][col]=1;
    int m=grid.size(),n=grid[0].size();
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            dfs(nrow,ncol,grid,vis);
    }
}

int numEnclaves(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size(),land=0;
    vector<vector<int>> vis(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        if(!vis[i][0] && grid[i][0]==1)
            dfs(i,0,grid,vis);
        if(!vis[i][n-1] && grid[i][n-1]==1)
            dfs(i,n-1,grid,vis);
    }
    for(int j=0;j<n;j++)
    {
        if(!vis[0][j] && grid[0][j]==1)
            dfs(0,j,grid,vis);
        if(!vis[m-1][j] && grid[m-1][j]==1)
            dfs(m-1,j,grid,vis);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
                land++;
        }
    }
    return land;
}
