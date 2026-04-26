// Input:
// s = "bbbab"
// Output:
// 4
// Explanation:
// One possible longest palindromic subsequence is "bbbb".

// Recursion
int lcs(int i,int j,int m,int n,string& s1,string& s2)
{
    if(i>=m || j>=n)
        return 0;
    if(s1[i]==s2[j])
        return 1+lcs(i+1,j+1,m,n,s1,s2);
    return max(lcs(i+1,j,m,n,s1,s2),lcs(i,j+1,m,n,s1,s2));
}

int longestPalindromeSubseq(string s)
{
    int n=s.size();
    string s1=s;
    reverse(s.begin(),s.end());
    string s2=s;
    return lcs(0,0,n,n,s1,s2);
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

int longestPalindromeSubseq(string s)
{
    int n=s.size();
    string s1=s;
    reverse(s.begin(),s.end());
    string s2=s;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return lcs(0,0,n,n,s1,s2,dp);
}

// Tabulation
int longestPalindromeSubseq(string s)
{
    int n=s.size();
    string s1=s;
    reverse(s.begin(),s.end());
    string s2=s;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
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
int longestPalindromeSubseq(string s)
{
    int n=s.size();
    string s1=s;
    reverse(s.begin(),s.end());
    string s2=s;
    vector<int> next(n+1,0);
    for(int i=n-1;i>=0;i--)
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
