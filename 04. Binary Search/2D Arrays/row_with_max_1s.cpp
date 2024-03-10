// Input: 
// m=3
// n=3
// matrix =
// [[1,1,1],
//  [0,0,1],
//  [0,0,0]]
// Output: 
// 0
// Explanation: 
// The 0th row of the given matrix has the maximum number of ones.

int firstoccur(vector<int>& v,int n)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(v[mid]>=1)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}
int rowWithMax1s(vector<vector<int>> &matrix, int m, int n)
{
    int maxi=0,ans=-1;
    for(int i=0;i<m;i++)
    {
        if(n-firstoccur(matrix[i],n)>maxi)
        {
            maxi=n-firstoccur(matrix[i],n);
            ans=i;
        }
    }
    return ans;
}
