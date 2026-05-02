// Input:
// s = "aa", p = "*"
// Output:
// true
// Explanation:
// '*' matches any sequence.

// Recursion
bool match(int i,int j,int m,int n,string& s1,string& s2)
{
    if(i>=m && j>=n)
        return true;
    if(i>=m && j<n)
        return false;
    if(i<m && j>=n)
    {
        for(int k=i;k<m;k++)
        {
            if(s1[k]!='*')
                return false;
        }
        return true;
    }
    if(s1[i]=='?' || s1[i]==s2[j])
        return match(i+1,j+1,m,n,s1,s2);
    if(s1[i]=='*')
        return match(i+1,j,m,n,s1,s2) || match(i,j+1,m,n,s1,s2);
    return false;
}

bool isMatch(string s,string p)
{
    int m=p.size(),n=s.size();
    return match(0,0,m,n,p,s);
}

// Memoization
bool match(int i,int j,int m,int n,string& s1,string& s2,vector<vector<int>>& dp)
{
    if(i>=m && j>=n)
        return true;
    if(i>=m && j<n)
        return false;
    if(i<m && j>=n)
    {
        for(int k=i;k<m;k++)
        {
            if(s1[k]!='*')
                return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]=='?' || s1[i]==s2[j])
        return dp[i][j]=match(i+1,j+1,m,n,s1,s2,dp);
    if(s1[i]=='*')
        return dp[i][j]=match(i+1,j,m,n,s1,s2,dp) || match(i,j+1,m,n,s1,s2,dp);
    return false;
}

bool isMatch(string s,string p)
{
    int m=p.size(),n=s.size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return match(0,0,m,n,p,s,dp);
}

// Tabulation
bool isMatch(string s2,string s1)
{
    int m=s1.size(),n=s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    dp[m][n]=1;
    for(int j=0;j<n;j++)
    {
        dp[m][j]=0;
    }
    for(int i=0;i<m;i++)
    {
        int flag=1;
        for(int k=i;k<m;k++)
        {
            if(s1[k]!='*')
            {
                flag=0;
                break;
            }
        }
        dp[i][n]=flag;
    }

    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(s1[i]=='?' || s1[i]==s2[j])
                dp[i][j]=dp[i+1][j+1];
            if(s1[i]=='*')
                dp[i][j]=dp[i+1][j] || dp[i][j+1];
        }
    }

    return dp[0][0];
}

// Space Optimization
bool isMatch(string s2,string s1)
{
    int m=s1.size(),n=s2.size();
    vector<int> next(n+1,0);

    next[n]=1;
    for(int j=0;j<n;j++)
    {
        next[j]=0;
    }

    for(int i=m-1;i>=0;i--)
    {
        vector<int> curr(n+1,0);
        int flag=1;
        for(int k=i;k<m;k++)
        {
            if(s1[k]!='*')
            {
                flag=0;
                break;
            }
        }
        curr[n]=flag;

        for(int j=n-1;j>=0;j--)
        {
            if(s1[i]=='?' || s1[i]==s2[j])
                curr[j]=next[j+1];
            if(s1[i]=='*')
                curr[j]=next[j] || curr[j+1];
        }
        next=curr;
    }

    return next[0];
}
