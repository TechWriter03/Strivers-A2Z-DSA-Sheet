// Input:
// mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output:
// [[0,0,0],[0,1,0],[1,2,1]]

vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
{
    int m=mat.size(),n=mat[0].size();
    vector<vector<int>> vis(m,vector<int>(n));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                vis[i][j]=1;
                q.push({{i,j},0});
            }
        }
    }
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    while(!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int dist=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && mat[nrow][ncol]==1)
            {
                vis[nrow][ncol]=1;
                mat[nrow][ncol]=dist+1;
                q.push({{nrow,ncol},dist+1});
            }
        }
    }
    return mat;
}
