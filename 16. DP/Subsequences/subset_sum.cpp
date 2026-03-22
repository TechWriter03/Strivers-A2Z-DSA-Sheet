// Input:
// arr = [1, 2, 3]
// sum = 6
// Output:
// true
// Explanation:
// The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

// Recursion
bool subset(int ind,int sum,int n,int target,vector<int>& arr)
{
    if(sum==target)
        return true;
    if(ind>=n)
        return false;
    if(sum>target)
        return false;
    int pick=subset(ind+1,sum+arr[ind],n,target,arr);
    int notPick=subset(ind+1,sum,n,target,arr);
    return (pick || notPick);
}

bool isSubsetSum(vector<int>& arr,int target)
{
    int n=arr.size();
    return subset(0,0,n,target,arr);
}

// Memoization
bool subset(int ind,int sum,int n,int target,vector<int>& arr,vector<vector<int>>& dp)
{
    if(sum==target)
        return true;
    if(ind>=n)
        return false;
    if(sum>target)
        return false;
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    int pick=subset(ind+1,sum+arr[ind],n,target,arr,dp);
    int notPick=subset(ind+1,sum,n,target,arr,dp);
    return dp[ind][sum]=(pick || notPick);
}

bool isSubsetSum(vector<int>& arr,int target)
{
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    return subset(0,0,n,target,arr,dp);
}

// Tabulation
bool isSubsetSum(vector<int>& arr,int target)
{
    int n=arr.size();
    vector<vector<bool>> dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    if(arr[0]<=target)
        dp[0][arr[0]]=true;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            bool notPick=dp[i-1][j];
            bool pick=false;
            if(arr[i]<=j)
                pick=dp[i-1][j-arr[i]];
            dp[i][j]=(pick || notPick);
        }
    }
    return dp[n-1][target];
}
