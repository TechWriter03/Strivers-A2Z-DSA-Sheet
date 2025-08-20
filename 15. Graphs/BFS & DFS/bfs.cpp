// Input:
// adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
// Output:
// [0, 2, 4, 3, 1]

vector<int> bfs(vector<vector<int>> &adj)
{
    int n=adj.size();
    vector<int> ans;
    vector<int> vis(n);
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
    return ans;
}
