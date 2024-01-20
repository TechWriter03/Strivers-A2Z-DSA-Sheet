// Input:
// N = 6
// A = [5, 8, 3, 2, 1, 4]
// Output:
// 5
// Explanation: 
// The resultant sequence can be 1, 2, 3, 4, 5.    
// The length of the sequence is 5.

int longestSuccessiveElements(vector<int>& a) 
{
    int n=a.size(),count,x,longest=1;
    unordered_set<int>st;
    for(auto it:a) st.insert(it);
    for(auto it:st)
    {
        if(st.find(it-1)==st.end())
        {
            x=it;
            count=1;
            while(st.find(x+1)!=st.end())
            {
                count++;
                x++;
            }
            longest=max(longest,count);
        }
    }
    return longest;
}
