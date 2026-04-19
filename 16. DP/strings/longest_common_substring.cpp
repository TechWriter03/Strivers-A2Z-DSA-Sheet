// Input:
// s1 = "ABCDGH", s2 = "ACDGHR"
// Output:
// 4
// Explanation:
// The longest common substring is "CDGH" with a length of 4.

// Tabulation
int longCommSubstr(string& s1,string& s2)
{
    int m=s1.size(),n=s2.size(),lcs=0;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j]=1+dp[i+1][j+1];
                lcs=max(dp[i][j],lcs);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    return lcs;
}

// Space Optimization
int longCommSubstr(string& s1,string& s2)
{
    int m=s1.size(),n=s2.size(),lcs=0;
    vector<int> next(n+1,0);
    for(int i=m-1;i>=0;i--)
    {
        vector<int> curr(n+1,0);
        for(int j=n-1;j>=0;j--)
        {
            if(s1[i]==s2[j])
            {
                curr[j]=1+next[j+1];
                lcs=max(curr[j],lcs);
            }
            else
            {
                curr[j]=0;
            }
        }
        next=curr;
    }
    return lcs;
}
