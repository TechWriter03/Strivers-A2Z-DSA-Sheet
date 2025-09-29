// Input:
// n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
// Output:
// 5
// Explanation:
// Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5.

vector<int> shortestPath(int n,int m,vector<vector<int>>& edges)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it:edges)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int> dist(n+1,1e9);
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[1]=0;
    pq.push({0,1});
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
                parent[neigh]=node;
                pq.push({dist[neigh],neigh});
            }
        }
    }
    if(dist[n]==1e9)
    {
        return {-1};
    }
    vector<int> path;
    int node=n;
    while(parent[node]!=node)
    {
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;
}
