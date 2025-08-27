// Input:
// adj[][]= [[3], [3], [], [0, 1]]
// src=3
// Output:
// [1, 1, -1, 0]

vector<int> shortestPath(vector<vector<int>>& adj,int src)
{
    int n=adj.size();
    vector<int> dist(n,-1);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}
