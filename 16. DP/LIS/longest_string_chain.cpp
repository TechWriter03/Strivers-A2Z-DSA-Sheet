// Input:
// words = ["a","b","ba","bca","bda","bdca"]
// Output:
// 4
// Explanation:
// One of the longest word chains is ["a","ba","bda","bdca"].

bool static comp(string& s1,string& s2)
{
    return s1.size()<s2.size();
}

bool check(string& s1,string& s2)
{
    int m=s1.size(),n=s2.size();
    if(m!=n+1)
        return false;
    int i=0,j=0;
    while(i<m)
    {
        if(j<n && s1[i]==s2[j])
            i++,j++;
        else
            i++;
    }
    if(i==m && j==n)
        return true;
    return false;
}

int longestStrChain(vector<string>& words)
{
    int n=words.size(),maxi=0;
    vector<int> dp(n,1);
    sort(words.begin(),words.end(),comp);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(check(words[i],words[j]) && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
        maxi=max(dp[i],maxi);
    }
    return maxi;
}
