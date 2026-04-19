// Input:
// text1 = "abcde", text2 = "ace"
// Output:
// 3
// Explanation:
// The longest common subsequence is "ace" and its length is 3.

// Recursion
int lcs(int i,int j,int m,int n,string& s1,string& s2)
{
    if(i>=m || j>=n)
        return 0;
    if(s1[i]==s2[j])
        return 1+lcs(i+1,j+1,m,n,s1,s2);
    return max(lcs(i+1,j,m,n,s1,s2),lcs(i,j+1,m,n,s1,s2));
}

int longestCommonSubsequence(string s1,string s2)
{
    int m=s1.size(),n=s2.size();
    return lcs(0,0,m,n,s1,s2);
}

// Memoization
int lcs(int i,int j,int m,int n,string& s1,string& s2,vector<vector<int>>& dp)
{
    if(i>=m || j>=n)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]==s2[j])
        return dp[i][j]=1+lcs(i+1,j+1,m,n,s1,s2,dp);
    return dp[i][j]=max(lcs(i+1,j,m,n,s1,s2,dp),lcs(i,j+1,m,n,s1,s2,dp));
}

int longestCommonSubsequence(string s1,string s2)
{
    int m=s1.size(),n=s2.size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return lcs(0,0,m,n,s1,s2,dp);
}

// Tabulation
int longestCommonSubsequence(string s1,string s2)
{
    int m=s1.size(),n=s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(s1[i]==s2[j])
                dp[i][j]=1+dp[i+1][j+1];
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}

// Space Optimization
int longestCommonSubsequence(string s1,string s2)
{
    int m=s1.size(),n=s2.size();
    vector<int> next(n+1,0);
    for(int i=m-1;i>=0;i--)
    {
        vector<int> curr(n+1,0);
        for(int j=n-1;j>=0;j--)
        {
            if(s1[i]==s2[j])
                curr[j]=1+next[j+1];
            else
                curr[j]=max(next[j],curr[j+1]);
        }
        next=curr;
    }
    return next[0];
}
