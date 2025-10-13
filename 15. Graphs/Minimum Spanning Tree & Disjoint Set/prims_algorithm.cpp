// Input:
// V = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
// Output:
// 4

int spanningTree(int V,vector<vector<int>>& edges)
{
    vector<vector<pair<int,int>>> adj(V);
    for(auto it:edges)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    int sum=0;
    vector<int> vis(V);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(vis[node])
        {
            continue;
        }
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node])
        {
            int neigh=it.first;
            int nwt=it.second;
            if(!vis[neigh])
            {
                pq.push({nwt,neigh});
            }
        }
    }
    return sum;
}
