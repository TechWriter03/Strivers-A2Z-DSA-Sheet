// Input:
// digits = "23"
// Output:
// ["ad","ae","af","bd","be","bf","cd","ce","cf"]

void combi(int ind,int n,string temp,string digits,string mp[],vector<string>& ans)
{
    if(ind==n)
    {
        ans.push_back(temp);
        return;
    }
    string s=mp[digits[ind]-'0'];
    for(int i=0;i<s.size();i++)
    {
        combi(ind+1,n,temp+s[i],digits,mp,ans);
    }
    return;
}
vector<string> letterCombinations(string digits)
{
    if(digits=="")
        return {};
    vector<string>ans;
    string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n=digits.size();
    combi(0,n,"",digits,mp,ans);
    return ans;
}
