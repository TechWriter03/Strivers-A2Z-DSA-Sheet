// Input: 
// candidates = [2,3,6,7]
// target = 7
// Output: 
// [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.

void generate(int ind,int sum,int target,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans)
{
    if(ind==arr.size())
        return;
    if(sum==target)
    {
        ans.push_back(ds);
        return;
    }
    if(sum<=target)
    {
        ds.push_back(arr[ind]);
        sum+=arr[ind];
        generate(ind,sum,target,arr,ds,ans);
        ds.pop_back();
        sum-=arr[ind];
    }
    generate(ind+1,sum,target,arr,ds,ans);
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    vector<vector<int>>ans;
    vector<int>ds;
    generate(0,0,target,candidates,ds,ans);
    return ans;
}
