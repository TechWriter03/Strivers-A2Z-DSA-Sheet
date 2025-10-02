// Input:
// n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output:
// 700
// Explanation:
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst,int k)
{
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:flights)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }
    vector<int> cost(n,1e9);
    queue<pair<int,pair<int,int>>> q;
    cost[src]=0;
    q.push({0,{src,0}});
    while(!q.empty())
    {
        auto ft=q.front();
        int stops=ft.first;
        int city=ft.second.first;
        int d=ft.second.second;
        q.pop();
        if(stops>k)
            continue;
        for(auto it:adj[city])
        {
            int neigh=it.first;
            int wt=it.second;
            if(d+wt<cost[neigh] && stops<=k)
            {
                cost[neigh]=d+wt;
                q.push({stops+1,{neigh,cost[neigh]}});
            }
        }
    }
    if(cost[dst]==1e9)
        return -1;
    return cost[dst];
}
