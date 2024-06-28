// Input: 
// nums = [1,2,2]
// Output: 
// [[],[1],[1,2],[1,2,2],[2],[2,2]]

void generate(int ind,int n,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans)
{
    ans.push_back(ds);
    for(int i=ind;i<n;i++)
    {
        if(i>ind && nums[i]==nums[i-1])
            continue;
        ds.push_back(nums[i]);
        generate(i+1,n,nums,ds,ans);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    vector<vector<int>>ans;
    vector<int>ds;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    generate(0,n,nums,ds,ans);
    return ans;
}
