// Input:
// V = 5
// edges[][] = [[0, 1], [2, 1], [3, 4]]
// Output:
// [[0, 1, 2], [3, 4]]

void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& temp)
{
    vis[node]=1;
    temp.push_back(node);
    for(auto it:adj[node])
    {
        if(!vis[it])
            dfs(it,adj,vis,temp);
    }
}

vector<vector<int>> getComponents(int V,vector<vector<int>>& edges)
{
    vector<vector<int>> ans;
    vector<int> vis(V);
    vector<vector<int>> adj(V);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            vector<int> temp;
            dfs(i,adj,vis,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
