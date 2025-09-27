// Input:
// V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
// Output:
// [4, 3, 0]
// Explanation:
// For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
// For 2 to 1 minimum distance will be 3. By following path 2 -> 1
// For 2 to 2 minimum distance will be 0. By following path 2 -> 2

vector<int> dijkstra(int V,vector<vector<int>>& edges,int src)
{
    vector<int> dist(V,1e9);
    vector<vector<pair<int,int>>> adj(V);
    for(auto it:edges)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node])
        {
            int neigh=it.first;
            int wt=it.second;
            if(d+wt<dist[neigh])
            {
                dist[neigh]=d+wt;
                pq.push({dist[neigh],neigh});
            }
        }
    }
    return dist;
}
