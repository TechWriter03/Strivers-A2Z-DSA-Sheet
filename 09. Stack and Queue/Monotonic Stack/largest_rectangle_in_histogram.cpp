// Input:
// heights = [2,1,5,6,2,3]
// Output:
// 10
// Explanation:
// The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

void findNSE(int n,vector<int>& heights,vector<int>& nse)
{
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
        if(st.empty())
            nse[i]=n;
        else
            nse[i]=st.top();
        st.push(i);
    }
}

void findPSE(int n,vector<int>& heights,vector<int>& pse)
{
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
        if(st.empty())
            pse[i]=-1;
        else
            pse[i]=st.top();
        st.push(i);
    }
}

int largestRectangleArea(vector<int>& heights)
{
    int n=heights.size(),maxArea=0;
    vector<int>nse(n),pse(n);
    findNSE(n,heights,nse);
    findPSE(n,heights,pse);
    for(int i=0;i<n;i++)
        maxArea=max(heights[i]*(nse[i]-pse[i]-1),maxArea);
    return maxArea;
}
