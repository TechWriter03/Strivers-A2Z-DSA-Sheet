// Input: 
// n = 3
// Output: 
// 2
// Explanation: 
// F(3) = F(2) + F(1) = 1 + 1 = 2.

// Recursion
int fibo(int n) 
{
    if(n==0) return 0;
    else if(n==1||n==2) return 1;
    return fibo(n-1)+fibo(n-2);
}

// Memoization
int fibo(int n,vector<int>& dp)
{
    if(n==0) return 0;
    else if(n==1||n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
}
int fib(int n) 
{
    vector<int>dp(n+1,-1);
    return fibo(n,dp);
}

// Tabulation
int fibo(int n) 
{
    if(n==0)
        return 0;
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

// Space Optimization
int fibo(int n) 
{
    if(n==0)
        return 0;
    int prev1=1,prev2=0,curr;
    for(int i=2;i<=n;i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
