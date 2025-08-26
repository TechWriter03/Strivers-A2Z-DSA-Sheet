// Input:
// graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output:
// [2,4,5,6]
// Explanation:
// The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<vector<int>> adjRev(n);
    vector<int> indegree(n);
    for(int i=0;i<n;i++)
    {
        for(auto it:graph[i])
        {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int> safe;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        safe.push_back(node);
        for(auto it:adjRev[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    sort(safe.begin(),safe.end());
    return safe;
}
