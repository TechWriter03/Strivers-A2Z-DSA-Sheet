// Input: 
// s = "abcabcbb"
// Output: 
// 3
// Explanation: 
// The answer is "abc", with the length of 3.

int lengthOfLongestSubstring(string s) 
{
    int n=s.size(),left=0,right=0,maxLen=0;
    int mp[256];
    for(int i=0;i<256;i++)
        mp[i]=-1;
    while(right<n)
    {
        if(mp[s[right]]!=-1)
        {
            if(mp[s[right]]>=left)
                left=mp[s[right]]+1;
        }
        int len=right-left+1;
        maxLen=max(maxLen,len);
        mp[s[right]]=right;
        right++;
    }
    return maxLen;
}
