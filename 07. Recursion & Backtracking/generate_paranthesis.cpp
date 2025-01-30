// Input:
// n = 3
// Output:
// ["((()))","(()())","(())()","()(())","()()()"]

bool isValid(string s)
{
    stack<char>st;
    for(auto it:s)
    {
        if(it=='(')
            st.push(it);
        else if(!st.empty() && it==')')
            st.pop();
        else
            return false;
    }
    return st.empty();
}
void generate(int n,string s,vector<string>& ans)
{
    if(s.size()==n*2 && isValid(s))
        ans.push_back(s);
    if(s.size()>n*2)
        return;
    generate(n,s+'(',ans);
    generate(n,s+')',ans);
}
vector<string> generateParenthesis(int n)
{
    vector<string>ans;
    generate(n,"",ans);
    return ans;
}
