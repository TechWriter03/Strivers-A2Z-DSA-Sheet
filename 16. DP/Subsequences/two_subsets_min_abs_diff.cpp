// Input:
// arr = [1, 6, 11, 5]
// Output:
// 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11 
// Hence, minimum difference is 1.

int minDifference(vector<int>& arr)
{
    int n=arr.size(),total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    
    int target=total/2;
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
    
    int minDiff=INT_MAX;
    for(int i=0;i<=target;i++)
    {
        if(dp[n-1][i])
        {
            int sum1=i,sum2=total-sum1;
            int diff=abs(sum1-sum2);
            minDiff=min(diff,minDiff);
        }
    }
    return minDiff;
}
