// Input:
// graph = [[1,1,0],[1,1,0],[0,0,1]]
// Output:
// 2

void dfs(int node,vector<vector<int>>& graph,vector<int>& vis)
{
    vis[node]=1;
    for(int i=0;i<graph.size();i++)
    {
        if(!vis[i] && graph[node][i])
            dfs(i,graph,vis);
    }
}

int findCircleNum(vector<vector<int>>& graph)
{
    int n=graph.size(),count=0;
    vector<int> vis(n);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(i,graph,vis);
        }
    }
    return count;
}
