// Input:
// s = "the sky is blue"
// Output:
// "blue is sky the"

string reverseWords(string s)
{
    int n=s.size();
    string temp,ans;
    vector<string>v;
    while(s[0]==' ')
    {
        s.erase(0,1);
        n--;
    }
    while(s[n-1]==' ')
    {
        s.erase(n-1,1);
        n--;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]!=' ')
        {
            temp+=s[i];
        }
        else
        {
            if(temp!="")
                v.push_back(temp);
            temp="";
        }
    }
    v.push_back(temp);
    int m=v.size();
    for(int i=m-1;i>=0;i--)
    {
        ans+=v[i];
        if(i>0)
            ans+=" ";
    }
    return ans;
}
