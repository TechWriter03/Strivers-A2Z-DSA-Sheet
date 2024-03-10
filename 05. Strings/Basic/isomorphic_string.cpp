// Input: 
// s = "paper"
// t = "title"
// Output: 
// true

bool isIsomorphic(string s, string t) 
{
    int n=s.size(),arr[96];
    map<char,char>mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(s[i])==mp.end() && arr[t[i]-' ']==0)
        {
            mp[s[i]]=t[i];
            arr[t[i]-' ']++;
        }
        else
        {
            if(mp[s[i]]!=t[i])
                return false;
        }
    }
    return true;
}
