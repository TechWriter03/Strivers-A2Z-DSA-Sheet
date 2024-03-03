// Input: 
// strs = ["flower","flow","flight"]
// Output: 
// "fl"

string longestCommonPrefix(vector<string>& strs) 
{
    int n=strs.size(),n1,n2,x,y;
    if(n==1)
        return strs[0];
    string temp="";
    vector<string>v;
    for(int i=0;i<n-1;i++)
    {
        n1=strs[i].size();
        n2=strs[i+1].size();
        x=0,y=0;
        while(x<n1 && y<n2)
        {
            if(strs[i][x]==strs[i+1][y])
                temp+=strs[i][x];
            else
                break;
            x++;
            y++;
        }
        if(v.empty())
            v.push_back(temp);
        if(temp.size()<v[0].size())
            v[0]=temp;
        temp="";
    }
    if(v.empty())
        return "";
    return v[0];
}
