// Input:
// nums = [1,2,1]
// Output:
// [2,-1,2]
// Explanation:
// The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

vector<int> nextGreaterElements(vector<int>& nums)
{
    int n=nums.size();
    vector<int>nge(n);
    stack<int>st;
    for(int i=2*n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=nums[i%n])
            st.pop();
        if(i<n)
        {
            if(st.empty())
                nge[i]=-1;
            else
                nge[i]=st.top();
        }
        st.push(nums[i%n]);
    }
    return nge;
}
