bool isValid(vector<vector<char>>& board,int row,int col,char ch)
{
  for(int k=0;k<9;k++)
  {
      if(board[row][k]==ch || board[k][col]==ch)
          return false;
      if(board[row/3*3 + k/3][col/3*3 + k%3]==ch)
          return false;
  }
  return true;
}
bool solve(vector<vector<char>>& board)
{
  for(int i=0;i<9;i++)
  {
      for(int j=0;j<9;j++)
      {
          if(board[i][j]=='.')
          {
              for(char ch='1';ch<='9';ch++)
              {
                  if(isValid(board,i,j,ch))
                  {
                      board[i][j]=ch;
                      if(solve(board))
                          return true;
                      else
                          board[i][j]='.';
                  }
              }
              return false;
          }
      }
  }
  return true;
}
void solveSudoku(vector<vector<char>>& board) 
{
  solve(board);
}
