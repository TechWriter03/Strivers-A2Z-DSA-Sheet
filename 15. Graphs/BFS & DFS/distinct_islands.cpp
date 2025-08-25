// Input:
// grid[][] = [[1, 1, 0, 0, 0],
//             [1, 1, 0, 0, 0],
//             [0, 0, 0, 1, 1],
//             [0, 0, 0, 1, 1]]
// Output:
// 1

void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int strow,int stcol,vector<pair<int,int>>& coord)
{
    vis[row][col]=1;
    coord.push_back({row-strow,col-stcol});
    int m=grid.size(),n=grid[0].size();
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            dfs(nrow,ncol,grid,vis,strow,stcol,coord);
    }
}

int countDistinctIslands(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> vis(m,vector<int>(n));
    set<vector<pair<int,int>>> unique;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            {
                vector<pair<int,int>> coord;
                dfs(i,j,grid,vis,i,j,coord);
                unique.insert(coord);
            }
        }
    }
    return unique.size();
}
