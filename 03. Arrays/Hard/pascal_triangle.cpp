// Input: 
// numRows = 5
// Output: 
// [[1],
//  [1,1],
//  [1,2,1],
//  [1,3,3,1],
//  [1,4,6,4,1]]

vector<int> rows(int m) 
{
    vector<int>row;
    int n=m,nr=1;
    for(int i=0;i<n;i++)
    {
        if(i>0) 
        {
            nr*=m;
            nr/=i;
        }
        row.push_back(nr);
        m--;
    }
    return row;
}
vector<vector<int>> generate(int numRows) 
{
    vector<vector<int>>ans(numRows);
    for(int i=0;i<numRows;i++)
        ans[i]=rows(i+1);
    return ans;
}
