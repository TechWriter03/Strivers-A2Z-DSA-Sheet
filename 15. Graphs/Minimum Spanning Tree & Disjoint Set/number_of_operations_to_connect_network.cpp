// Input:
// n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 
// 1
// Explanation:
// Remove cable between computer 1 and 2 and place between computers 1 and 3.

class DisjointSet
{
public:
    vector<int> size,parent;

    DisjointSet(int n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
        }
    }

    int findUParent(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=findUParent(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int pu=findUParent(u),pv=findUParent(v);
        if(pu==pv)
            return;
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution 
{
public:
    int makeConnected(int n,vector<vector<int>>& connections)
    {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:connections)
        {
            int u=it[0],v=it[1];
            if(ds.findUParent(u)==ds.findUParent(v))
                extra++;
            else
                ds.unionBySize(u,v);
        }
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
                components++;
        }
        int ans=components-1;
        if(extra>=ans)
            return ans;
        return -1;
    }
};
