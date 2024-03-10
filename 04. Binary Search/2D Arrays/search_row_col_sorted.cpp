// Input: 
// matrix =
// [[1,4,7,11,15],
//  [2,5,8,12,19],
//  [3,6,9,16,22],
//  [10,13,14,17,24],
//  [18,21,23,26,30]]
// target = 5
// Output: 
// true

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m=matrix.size(),n=matrix[0].size();
    int row=0,col=n-1;
    while(row<=m-1 && col>=0)
    {
        if(matrix[row][col]==target)
            return true; 
        else if(matrix[row][col]<target)
            row++;
        else
            col--;
    }
    for(int i=row;i<m;i++)
        for(int j=0;j<=col;j++)
            if(matrix[i][j]==target)
                return true;
    return false;
}
