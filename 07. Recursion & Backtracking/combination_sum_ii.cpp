// Input:
// candidates = [10,1,2,7,6,1,5]
// target = 8
// Output: 
// [[1,1,6],
//  [1,2,5],
//  [1,7],
//  [2,6]]

void generate(int ind,int sum,int t,int n,vector<int>& cds,vector<int>& ds,vector<vector<int>>& ans)
{
    if(ind>n || sum>t)
        return;
    if(sum==t)
    {
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<n;i++)
    {
        if(i>ind && cds[i]==cds[i-1])
            continue;
        ds.push_back(cds[i]);
        generate(i+1,sum+cds[i],t,n,cds,ds,ans);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& cds, int t) 
{
    vector<vector<int>>ans;
    vector<int>ds;
    int n=cds.size();
    sort(cds.begin(),cds.end());
    generate(0,0,t,n,cds,ds,ans);
    return ans;
}
