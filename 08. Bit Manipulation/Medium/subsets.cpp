// Input:
// nums = [1,2,3]
// Output:
// [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    int n=nums.size(),m=1<<n;
    for(int i=0;i<m;i++)
    {
        vector<int> ds;
        for(int j=0;j<n;j++)
            if(1&(i>>j))
                ds.push_back(nums[j]);
        ans.push_back(ds);
    }
    return ans;
}
