// Input: 
// s = "ABAB", k = 2
// Output: 
// 4
// Explanation: 
// Replace the two 'A's with two 'B's or vice versa.

int characterReplacement(string s, int k) 
{
    int n=s.size(),left=0,right=0,maxfq=0,maxLen=0,freq[26];
    while(right<n)
    {
        freq[s[right]-'A']++;
        maxfq=max(maxfq,freq[s[right]-'A']);
        if((right-left+1)-maxfq>k)
        {
            freq[s[left]-'A']--;
            left++;
        }
        maxLen=max(maxLen,right-left+1);
        right++;
    }
    return maxLen;
}
