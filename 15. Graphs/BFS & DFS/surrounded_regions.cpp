// Input:
// board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output:
// [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis)
{
    vis[row][col]=1;
    int m=board.size(),n=board[0].size();
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O')
            dfs(nrow,ncol,board,vis);
    }
}

void solve(vector<vector<char>>& board)
{
    int m=board.size(),n=board[0].size();
    vector<vector<int>> vis(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        if(!vis[i][0] && board[i][0]=='O')
            dfs(i,0,board,vis);
        if(!vis[i][n-1] && board[i][n-1]=='O')
            dfs(i,n-1,board,vis);
    }
    for(int j=0;j<n;j++)
    {
        if(!vis[0][j] && board[0][j]=='O')
            dfs(0,j,board,vis);
        if(!vis[m-1][j] && board[m-1][j]=='O')
            dfs(m-1,j,board,vis);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j] && board[i][j]=='O')
                board[i][j]='X';
        }
    }
}
