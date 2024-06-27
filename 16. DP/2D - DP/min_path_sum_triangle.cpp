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
int minPath(vector<vector<int>>& arr,int n,int row,int col)
{
    if(row==n-1) 
        return arr[row][col];
    int down = minPath(arr,n,row+1,col);
    int cross = minPath(arr,n,row+1,col+1);
    return arr[row][col] + min(down,cross);
}
int minimumTotal(vector<vector<int>>& triangle) 
{
    int n=triangle.size();
    return minPath(triangle,n,0,0);
}

// Memoization
int minPath(vector<vector<int>>& arr,int n,int row,int col,vector<vector<int>>& dp)
{
    if(row==n-1) 
        return arr[row][col];
    if(dp[row][col]!=-1)
        return dp[row][col];
    int down = minPath(arr,n,row+1,col,dp);
    int cross = minPath(arr,n,row+1,col+1,dp);
    return dp[row][col] = arr[row][col] + min(down,cross);
}
int minimumTotal(vector<vector<int>>& triangle) 
{
    int n=triangle.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return minPath(triangle,n,0,0,dp);
}

// Tabulation
int minimumTotal(vector<vector<int>>& arr) 
{
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n));
    for(int i=0;i<n;i++)
        dp[n-1][i] = arr[n-1][i];
    for(int i=n-2;i>=0;i--)
        for(int j=i;j>=0;j--)
            dp[i][j]=arr[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
    return dp[0][0];
}

// Space Optimization
int minimumTotal(vector<vector<int>>& arr) 
{
    int n=arr.size();
    vector<int>curr(n),next(n);
    for(int i=0;i<n;i++)
        next[i] = arr[n-1][i];
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
            curr[j]=arr[i][j]+min(next[j],next[j+1]);
        next=curr;
    }
    return next[0];
}
