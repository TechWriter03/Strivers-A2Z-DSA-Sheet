// Input:
// V = 4
// edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output:
// true

bool dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,node,adj,vis))
                return true;
        }
        else if(it!=parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V,vector<vector<int>>& edges)
{
    vector<vector<int>> adj(V);
    vector<int> vis(V);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,adj,vis))
                return true;
        }
    }
    return false;
}
