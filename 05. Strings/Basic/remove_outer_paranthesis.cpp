// Input:
// s = "(()())(())"
// Output:
// "()()()"
// Explanation: 
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

string removeOuterParentheses(string s)
{
    string temp="",ans="";
    int count=0;
    for(auto it:s)
    {
        temp+=it;
        if(it=='(')
            count++;
        else
            count--;
        if(count==0)
        {
            temp.erase(0,1);
            temp.erase(temp.size()-1,1);
            ans+=temp;
            temp="";
        }
    }
    return ans;
}
