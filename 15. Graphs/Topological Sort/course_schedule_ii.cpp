// Input:
// n = 4
// prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output:
// [0,2,1,3]
// Explanation:
// There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
// Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

vector<int> findOrder(int n,vector<vector<int>>& prereq)
{
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for(auto it:prereq)
    {
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int> topoSort;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    if(topoSort.size()==n)
        return topoSort;
    return {};
}
