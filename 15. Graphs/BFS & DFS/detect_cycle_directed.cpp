// Input:
// V = 4
// edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]
// Output:
// true

bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathVis)
{
    vis[node]=1;
    pathVis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,adj,vis,pathVis))
                return true;
        }
        else if(pathVis[it])
        {
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}

bool isCyclic(int V,vector<vector<int>>& edges)
{
    vector<vector<int>> adj(V);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<int> vis(V);
    vector<int> pathVis(V);
    for(int i=0;i<V;i++)
    {
        if(!vis[i] && dfs(i,adj,vis,pathVis))
            return true;
    }
    return false;
}
