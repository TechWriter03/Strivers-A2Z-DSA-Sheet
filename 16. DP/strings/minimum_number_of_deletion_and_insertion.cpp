// Input:
// s1 = "heap", s2 = "pea"
// Output:
// 3
// Explanation:
// 'p' and 'h' deleted from heap. Then, 'p' is inserted at the beginning.

// Tabulation
int minOperations(string& s1,string& s2)
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
    return m+n-2*dp[0][0];
}

// Space Optimization
int minOperations(string& s1,string& s2)
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
    return m+n-2*next[0];
}
