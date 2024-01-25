// Input: 
// matrix = 
// [[1,2,3,4],
//  [5,6,7,8],
//  [9,10,11,12]]
// Output: 
// [1,2,3,4,8,12,11,10,9,5,6,7]

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    int m=matrix.size(),n=matrix[0].size();
    vector<int>ans;
    int t=0,l=0,b=m-1,r=n-1;
    while(t<=b && l<=r)
    {
        for(int i=l;i<=r;i++)
            ans.push_back(matrix[t][i]);
        t++;
        for(int i=t;i<=b;i++)
            ans.push_back(matrix[i][r]);
        r--;
        if(t<=b)
            for(int i=r;i>=l;i--)
                ans.push_back(matrix[b][i]);
        b--;
        if(l<=r)
            for(int i=b;i>=t;i--)
                ans.push_back(matrix[i][l]);
        l++;
    }
    return ans;
}
