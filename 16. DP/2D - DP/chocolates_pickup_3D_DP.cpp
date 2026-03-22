// Input:
// grid = [[4, 1, 2], [3, 6, 1], [1, 6, 6], [3, 1, 2]]
// Output:
// 32
// Explanation:
// The path followed by first robot is: (0, 0) -> (1, 0) -> (2, 1) -> (3, 0), so first robot collected: 4 + 3 + 6 + 3 = 16 chocolates.
// The path followed by second robot is: (0, 2) -> (1, 1) -> (2, 2) -> (3, 2), so second robot collected: 2 + 6 + 6 + 2 = 16 chocolates.
// Total both robots collected 16 + 16 = 32 chocolates.

// Recursion
int maxPath(int row,int col1,int col2,int m,int n,vector<vector<int>>& grid)
{
    if(col1<0 || col1>=n || col2<0 || col2>=n)
        return INT_MIN;
    if(row==m-1)
    {
        if(col1==col2)
            return grid[row][col1];
        else
            return grid[row][col1]+grid[row][col2];
    }
    int maxSum=INT_MIN;
    for(int dc1=-1;dc1<=1;dc1++)
    {
        for(int dc2=-1;dc2<=1;dc2++)
        {
            int dcol1=col1+dc1,dcol2=col2+dc2;
            int total=0;
            if(col1==col2)
            {
                total+=grid[row][col1]+maxPath(row+1,dcol1,dcol2,m,n,grid);
            }
            else
            {
                total+=grid[row][col1]+grid[row][col2]+maxPath(row+1,dcol1,dcol2,m,n,grid);
            }
            maxSum=max(total,maxSum);
        }
    }
    return maxSum;
}

int maxChocolate(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    return maxPath(0,0,n-1,m,n,grid);
}

// Memoization
int maxPath(int row,int col1,int col2,int m,int n,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
{
    if(col1<0 || col1>=n || col2<0 || col2>=n)
        return INT_MIN;
    if(row==m-1)
    {
        if(col1==col2)
            return grid[row][col1];
        else
            return grid[row][col1]+grid[row][col2];
    }
    if(dp[row][col1][col2]!=-1)
        return dp[row][col1][col2];
    int maxSum=INT_MIN;
    for(int dc1=-1;dc1<=1;dc1++)
    {
        for(int dc2=-1;dc2<=1;dc2++)
        {
            int dcol1=col1+dc1,dcol2=col2+dc2;
            int total=0;
            if(col1==col2)
            {
                total+=grid[row][col1]+maxPath(row+1,dcol1,dcol2,m,n,grid,dp);
            }
            else
            {
                total+=grid[row][col1]+grid[row][col2]+maxPath(row+1,dcol1,dcol2,m,n,grid,dp);
            }
            maxSum=max(total,maxSum);
        }
    }
    return dp[row][col1][col2]=maxSum;
}

int maxChocolate(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(n,-1)));
    return maxPath(0,0,n-1,m,n,grid,dp);
}

// Tabulation
int maxChocolate(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0)));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                dp[m-1][i][j]=grid[m-1][i];
            else
                dp[m-1][i][j]=grid[m-1][i]+grid[m-1][j];
        }
    }
    
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            for(int k=n-1;k>=0;k--)
            {
                int maxSum=INT_MIN;
                for(int dc1=-1;dc1<=1;dc1++)
                {
                    for(int dc2=-1;dc2<=1;dc2++)
                    {
                        int j1=j+dc1,j2=k+dc2;
                        int total=0;
                        if(j1<0 || j1>=n || j2<0 || j2>=n)
                            continue;
                        if(j==k)
                        {
                            total+=grid[i][j]+dp[i+1][j1][j2];
                        }
                        else
                        {
                            total+=grid[i][j]+grid[i][k]+dp[i+1][j1][j2];
                        }
                        maxSum=max(total,maxSum);
                    }
                }
                dp[i][j][k]=maxSum;
            }
        }
    }
    
    return dp[0][0][n-1];
}
