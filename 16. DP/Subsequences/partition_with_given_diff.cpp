// Input:
// arr = [5, 2, 6, 4]
// diff = 3
// Output:
// 1
// Explanation:
// There is only one possible partition of this array. Partition : [6, 4], [5, 2].
// The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

// Tabulation
int countPartitions(vector<int>& arr,int diff)
{
    int n=arr.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    
    if((total-diff)<0 || (total-diff)%2==1)
        return 0;
    
    int target=(total-diff)/2;
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[n][target]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=target;j>=0;j--)
        {
            int notPick=dp[i+1][j];
            int pick=0;
            if(j+arr[i]<=target)
                pick=dp[i+1][j+arr[i]];
            dp[i][j]=pick+notPick;
        }
    }
    
    return dp[0][0];
}

// Space Optimization
int countPartitions(vector<int>& arr,int diff)
{
    int n=arr.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    
    if((total-diff)<0 || (total-diff)%2==1)
        return 0;
    
    int target=(total-diff)/2;
    vector<int> next(target+1,0);
    next[target]=1;
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(target+1,0);
        for(int j=target;j>=0;j--)
        {
            int notPick=next[j];
            int pick=0;
            if(j+arr[i]<=target)
                pick=next[j+arr[i]];
            curr[j]=pick+notPick;
        }
        next=curr;
    }
    
    return next[0];
}
