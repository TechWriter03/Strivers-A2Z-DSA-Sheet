// Input:
// V = 4
// edges[][] = [[3, 0], [1, 0], [2, 0]]
// Output:
// [3, 2, 1, 0] or [1, 2, 3, 0] or [2, 3, 1, 0]

vector<int> topoSort(int V,vector<vector<int>>& edges)
{
    vector<vector<int>> adj(V);
    vector<int> indegree(V);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int> topoSort;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    return topoSort;
}
