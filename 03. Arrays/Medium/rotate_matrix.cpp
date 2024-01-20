// Input: 
// matrix = 
// [[1,2,3],
//  [4,5,6],
//  [7,8,9]]
// Output: 
// [[7,4,1],
//  [8,5,2],
//  [9,6,3]]

void rotate(vector<vector<int>>& matrix) 
{
    int n=matrix.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
            swap(matrix[i][j],matrix[j][i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
            swap(matrix[i][j],matrix[i][n-j-1]);   
    }    
}
