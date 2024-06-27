// Input: 
// nums = [1,2,3]
// Output: 
// [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

void generate(int ind,int n,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans)
{
    if(ind==n)
    {
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[ind]);
    generate(ind+1,n,nums,ds,ans);
    ds.pop_back();
    generate(ind+1,n,nums,ds,ans);
    return;
}
vector<vector<int>> subsets(vector<int>& nums)
{
    int n=nums.size();
    vector<int>ds;
    vector<vector<int>>ans;
    generate(0,n,nums,ds,ans);
    return ans;
}
