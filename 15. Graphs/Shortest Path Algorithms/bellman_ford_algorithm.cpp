// Input:
// V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0
// Output:
// [0, 5, 6, 6, 7]
// Explanation:
// Shortest Paths:
// For 0 to 1 minimum distance will be 5. By following path 0 → 1
// For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
// For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3 
// For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4

vector<int> bellmanFord(int V,vector<vector<int>>& edges,int src)
{
    vector<int> dist(V,1e8);
    dist[src]=0;
    for(int i=0;i<V-1;i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
    }
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v])
        {
            return {-1};
        }
    }
    return dist;
}
