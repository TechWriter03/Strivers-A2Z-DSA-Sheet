// Input:
// arr = [1, 1, 1, 1, 1], target = 3
// Output:
// 5
// Explanation:
// There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// Recursion
int countWays(int ind,int sum1,int n,int total,int target,vector<int>& arr)
{
    int sum2=total-sum1;
    if(ind==n)
    {
        if(sum1-sum2==target)
            return 1;
        return 0;
    }
    int pick=countWays(ind+1,sum1+arr[ind],n,total,target,arr);
    int notPick=countWays(ind+1,sum1,n,total,target,arr);
    return pick+notPick;
}

int totalWays(vector<int>& arr,int target)
{
    int n=arr.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    return countWays(0,0,n,total,target,arr);
}

// Memoization
int countWays(int ind,int sum1,int n,int total,int target,vector<int>& arr,vector<vector<int>>& dp)
{
    int sum2=total-sum1;
    if(ind==n)
    {
        if(sum1-sum2==target)
            return 1;
        return 0;
    }
    if(dp[ind][sum1]!=-1)
        return dp[ind][sum1];
    int pick=countWays(ind+1,sum1+arr[ind],n,total,target,arr,dp);
    int notPick=countWays(ind+1,sum1,n,total,target,arr,dp);
    return dp[ind][sum1]=pick+notPick;
}

int totalWays(vector<int>& arr,int target)
{
    int n=arr.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(total+1,-1));
    return countWays(0,0,n,total,target,arr,dp);
}

// Tabulation
int totalWays(vector<int>& arr,int target)
{
    int n=arr.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    if((total-target)<0 || (total-target)%2==1)
        return 0;
    int k=(total-target)/2;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    dp[n][k]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=k;j>=0;j--)
        {
            int notPick=dp[i+1][j];
            int pick=0;
            if(j+arr[i]<=k)
                pick=dp[i+1][j+arr[i]];
            dp[i][j]=pick+notPick;
        }
    }
    return dp[0][0];
}