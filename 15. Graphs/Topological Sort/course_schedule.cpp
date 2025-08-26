// Input:
// n = 2
// prerequisites = [[1,0]]
// Output:
// true
// Explanation:
// There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

bool canFinish(int n,vector<vector<int>>& prereq)
{
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for(auto it:prereq)
    {
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        count++;
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    return (count==n);
}
