// Input: 
// matrix = 
// [[0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]]
// Output: 
// [[0,0,0,0],
//  [0,4,5,0],
//  [0,3,1,0]]

void setZeroes(vector<vector<int>>& matrix) 
{
    int m=matrix.size(),n=matrix[0].size();
    vector<int>row(m,1),col(n,1);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
                row[i]=0;
                col[j]=0;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((row[i]==0 || col[j]==0) && matrix[i][j]!=0)
                matrix[i][j]=0;
        }
    }
}
