// Input:
// s = "(1+(2*3)+((8)/4))+1"
// Output:
// 3
// Explanation:
// Digit 8 is inside of 3 nested parentheses in the string.

int maxDepth(string s)
{
    int count=0,ans=0;
    for(auto it:s)
    {
        if(it=='(')
            ans=max(ans,++count);
        if(it==')')
            count--;
    }
    return ans;
}
