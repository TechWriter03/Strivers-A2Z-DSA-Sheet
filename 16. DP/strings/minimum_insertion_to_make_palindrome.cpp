// Input:
// s = "leetcode"
// Output:
// 5
// Explanation:
// Inserting 5 characters the string becomes "leetcodocteel".

// Tabulation
int minInsertions(string s)
{
    int n=s.size();
    string t=s;
    reverse(t.begin(),t.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(s[i]==t[j])
                dp[i][j]=1+dp[i+1][j+1];
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    return n-dp[0][0];
}

// Space Optimization
int minInsertions(string s)
{
    int n=s.size();
    string t=s;
    reverse(t.begin(),t.end());
    vector<int> next(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        vector<int> curr(n+1,0);
        for(int j=n-1;j>=0;j--)
        {
            if(s[i]==t[j])
                curr[j]=1+next[j+1];
            else
                curr[j]=max(next[j],curr[j+1]);
        }
        next=curr;
    }
    return n-next[0];
}
