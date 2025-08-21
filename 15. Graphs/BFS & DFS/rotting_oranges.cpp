// Input:
// grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output:
// 4

int orangesRotting(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size(),fresh=0,finalTime=0;
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
                fresh++;
            if(grid[i][j]==2)
                q.push({{i,j},0});
        }
    }
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    while(!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int time=q.front().second;
        finalTime=time;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
            {
                fresh--;
                grid[nrow][ncol]=2;
                q.push({{nrow,ncol},time+1});
            }
        }
    }
    return (fresh==0)? finalTime : -1;
}
