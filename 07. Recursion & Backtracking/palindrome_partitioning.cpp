// Input: 
// s = "aab"
// Output: 
// [["a","a","b"],["aa","b"]]

bool isPalindrome(string s)
{
    int n=s.size(),i=0;
    while(i<n/2)
    {
        if(s[i]!=s[n-i-1])
            return false;
        i++;
    }
    return true;
}

void separate(vector<vector<string>>& ans,vector<string>& temp,string s,int ind,int n)
{
    if(ind==n)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<n;i++)
    {
        string sub=s.substr(ind,i-ind+1);
        if(isPalindrome(sub))
        {
            temp.push_back(sub);
            cout<<sub<<" ";
            separate(ans,temp,s,i+1,n);
            temp.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string s) 
{
    vector<string>temp;
    vector<vector<string>>ans;
    int n=s.size();
    separate(ans,temp,s,0,n);
    return ans;
}
