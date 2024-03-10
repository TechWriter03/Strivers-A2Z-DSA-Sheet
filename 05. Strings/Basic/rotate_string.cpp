// Input: 
// s = "abcde"
// goal = "cdeab"
// Output: 
// true

bool isCyclicRotation(string s, string g) 
{
    int m=s.size(),n=g.size();
    if(m!=n)
        return false;
    s+=s;
    if(s.find(g)!=string::npos)
        return true;
    return false;
}
