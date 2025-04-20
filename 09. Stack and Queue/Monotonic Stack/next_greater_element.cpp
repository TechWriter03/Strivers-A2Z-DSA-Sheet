// Input:
// arr[] = [6, 8, 0, 1, 3]
// Output:
// [8, -1, 1, 3, -1]

vector<int> nextLargerElement(vector<int>& arr)
{
    int n=arr.size();
    vector<int>nge(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
            st.pop();
        if(st.empty())
            nge[i]=-1;
        else
            nge[i]=st.top();
        st.push(arr[i]);
    }
    return nge;
}
