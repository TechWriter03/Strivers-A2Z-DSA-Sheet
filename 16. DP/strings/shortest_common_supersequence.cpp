// Input:
// str1 = "abac", str2 = "cab"
// Output:
// "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.

string shortestCommonSupersequence(string s1,string s2)
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

    string ans="";
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(s1[i]==s2[j])
        {
            ans+=s1[i];
            i++;
            j++;
        }
        else if(dp[i+1][j]>dp[i][j+1])
        {
            ans+=s1[i];
            i++;
        }
        else
        {
            ans+=s2[j];
            j++;
        }
    }

    while(i<m)
    {
        ans+=s1[i];
        i++;
    }
    while(j<n)
    {
        ans+=s2[j];
        j++;
    }

    return ans;
}
