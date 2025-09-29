// Input:
// grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output:
// 4

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> vis(m,vector<int>(n));
    queue<pair<int,pair<int,int>>> q;
    if(grid[0][0]==0)
    {
        vis[0][0]=1;
        q.push({1,{0,0}});
    }
    while(!q.empty())
    {
        int d=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
        if(row==m-1 && col==n-1)
        {
            return d;
        }
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nrow=row+i;
                int ncol=col+j;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({d+1,{nrow,ncol}});
                }
            }
        }
    }
    return -1;
}
