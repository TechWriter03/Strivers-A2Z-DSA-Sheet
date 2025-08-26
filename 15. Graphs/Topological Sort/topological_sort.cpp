// Input:
// V = 4
// edges[][] = [[3, 0], [1, 0], [2, 0]]
// Output:
// [3, 2, 1, 0] or [1, 2, 3, 0] or [2, 3, 1, 0]

void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,stack<int>& st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
            dfs(it,adj,vis,st);
    }
    st.push(node);
}

vector<int> topoSort(int V,vector<vector<int>>& edges)
{
    vector<vector<int>> adj(V);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<int> vis(V);
    stack<int> st;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
            dfs(i,adj,vis,st);
    }
    vector<int> topoSort;
    while(!st.empty())
    {
        topoSort.push_back(st.top());
        st.pop();
    }
    return topoSort;
}
