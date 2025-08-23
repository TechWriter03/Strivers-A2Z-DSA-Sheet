// Input:
// graph = [[1,3],[0,2],[1,3],[0,2]]
// Output:
// true
// Explanation:
// We can partition the nodes into two sets: {0, 2} and {1, 3}.

// BFS
bool bfs(int src,vector<vector<int>>& graph,vector<int>& colour)
{
    queue<int> q;
    colour[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:graph[node])
        {
            if(colour[it]==-1)
            {
                colour[it]=1-colour[node];
                q.push(it);
            }
            else if(colour[it]==colour[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<int> colour(n,-1);
    for(int i=0;i<n;i++)
    {
        if(colour[i]==-1 && !bfs(i,graph,colour))
            return false;
    }
    return true;
}

// DFS
bool dfs(int node,int col,vector<vector<int>>& graph,vector<int>& colour)
{
    colour[node]=col;
    for(auto it:graph[node])
    {
        if(colour[it]==-1)
        {
            if(!dfs(it,1-colour[node],graph,colour))
                return false;
        }
        else if(colour[it]==colour[node])
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<int> colour(n,-1);
    for(int i=0;i<n;i++)
    {
        if(colour[i]==-1 && !dfs(i,0,graph,colour))
            return false;
    }
    return true;
}
