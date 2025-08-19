// Input:
// adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
// Output:
// [0, 2, 4, 3, 1]

void DFS(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& ans)
{
    vis[node]=1;
    ans.push_back(node);
    for(auto it:adj[node])
    {
        if(!vis[it])
            DFS(it,adj,vis,ans);
    }
}

vector<int> dfs(vector<vector<int>>& adj)
{
    int n=adj.size();
    vector<int> ans;
    vector<int> vis(n);
    DFS(0,adj,vis,ans);
    return ans;
}
