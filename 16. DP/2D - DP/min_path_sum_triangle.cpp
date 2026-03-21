// Input: 
// triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 
// 11
// Explanation: 
// The triangle looks like:
// 2
// 3 4
// 6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.

// Recursion
int minPath(int row,int col,int n,vector<vector<int>>& triangle)
{
    if(row==n-1)
        return triangle[row][col];
    int down=minPath(row+1,col,n,triangle);
    int cross=minPath(row+1,col+1,n,triangle);
    return triangle[row][col]+min(down,cross);
}

int minimumTotal(vector<vector<int>>& triangle)
{
    int n=triangle.size();
    return minPath(0,0,n,triangle);
}

// Memoization
int minPath(int row,int col,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
{
    if(row==n-1)
        return triangle[row][col];
    if(dp[row][col]!=-1)
        return dp[row][col];
    int down=minPath(row+1,col,n,triangle,dp);
    int cross=minPath(row+1,col+1,n,triangle,dp);
    return dp[row][col]=triangle[row][col]+min(down,cross);
}

int minimumTotal(vector<vector<int>>& triangle)
{
    int n=triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return minPath(0,0,n,triangle,dp);
}

// Tabulation
int minimumTotal(vector<vector<int>>& triangle)
{
    int n=triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        dp[n-1][i]=triangle[n-1][i];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int down=dp[i+1][j];
            int cross=dp[i+1][j+1];
            dp[i][j]=triangle[i][j]+min(down,cross);
        }
    }
    return dp[0][0];
}

// Space Optimization
int minimumTotal(vector<vector<int>>& triangle)
{
    int n=triangle.size();
    vector<int> next(n,0);
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(n,0);
        for(int j=i;j>=0;j--)
        {
            if(i==n-1)
            {
                curr[j]=triangle[n-1][j];
            }
            else
            {
                int down=next[j];
                int cross=next[j+1];
                curr[j]=triangle[i][j]+min(down,cross);
            }
        }
        next=curr;
    }
    return next[0];
}
