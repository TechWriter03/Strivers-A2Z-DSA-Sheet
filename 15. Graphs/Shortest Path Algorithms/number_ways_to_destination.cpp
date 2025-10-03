// Input:
// n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
// Output:
// 4
// Explanation:
// The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
// The four ways to get there in 7 minutes are:
// - 0 ➝ 6
// - 0 ➝ 4 ➝ 6
// - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
// - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

int countPaths(int n,vector<vector<int>>& roads)
{
    int mod=1e9+7;
    vector<vector<pair<int,long>>> adj(n);
    for(auto it:roads)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<long> dist(n,1e12);
    vector<int> ways(n);
    priority_queue<pair<long,int>,vector<pair<long,int>>,greater<>> pq;
    dist[0]=0;
    ways[0]=1;
    pq.push({0,0});
    while(!pq.empty())
    {
        long d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node])
        {
            int neigh=it.first;
            long wt=it.second;
            if(d+wt<dist[neigh])
            {
                dist[neigh]=d+wt;
                pq.push({dist[neigh],neigh});
                ways[neigh]=ways[node];
            }
            else if(d+wt==dist[neigh])
            {
                ways[neigh]+=ways[node];
                ways[neigh]%=mod;
            }
        }
    }
    return ways[n-1];
}
