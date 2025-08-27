// Input:
// V = 4, E = 2
// edges = [[0,1,2], [0,2,1]]
// Output:
// [0, 2, 1, -1]
// Explanation:
// Shortest path from 0 to 1 is 0->1 with edge weight 2.
// Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.

vector<int> shortestPath(int V,int E,vector<vector<int>>& edges)
{
    vector<vector<pair<int,int>>>adj(V);
    vector<int> indegree(V);
    for(auto it:edges)
    {
        int u=it[0],v=it[1],wt=it[2];
        adj[u].push_back({v,wt});
        indegree[v]++;
    }
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int>topoSort;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto it:adj[node])
        {
            int v=it.first;
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
    }
    vector<int> dist(V,1e9);
    dist[0]=0;
    for(auto u:topoSort)
    {
        for(auto it:adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if(dist[u]+wt<dist[v])
                dist[v]=dist[u]+wt;
        }
    }
    for(int i=0;i<V;i++)
    {
        if(dist[i]==1e9)
            dist[i]=-1;
    }
    return dist;
}
