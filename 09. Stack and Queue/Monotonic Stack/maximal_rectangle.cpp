// Input:
// matrix = 
// [["1","0","1","0","0"],
//  ["1","0","1","1","1"],
//  ["1","1","1","1","1"],
//  ["1","0","0","1","0"]]
// Output:
// 6

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

int largestRectHist(vector<int>& heights)
{
    int n=heights.size(),maxArea=0;
    vector<int>nse(n),pse(n);
    findNSE(n,heights,nse);
    findPSE(n,heights,pse);
    for(int i=0;i<n;i++)
        maxArea=max(heights[i]*(nse[i]-pse[i]-1),maxArea);
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    int m=matrix.size(),n=matrix[0].size(),maxArea=0;
    vector<vector<int>>preSum(m,vector<int>(n));
    for(int j=0;j<n;j++)
    {
        int sum=0;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][j]!='0')
            {
                sum++;
                preSum[i][j]=sum;
            }
            else
            {
                sum=0;
            }
        }
    }
    for(int i=0;i<m;i++)
        maxArea=max(largestRectHist(preSum[i]),maxArea);
    return maxArea;
}
