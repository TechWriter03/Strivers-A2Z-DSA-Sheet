// Input:
// V = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
// Output:
// 4

class DisjointSet
{
private:
    vector<int> size,parent;
    
public:
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
    int spanningTree(int V,vector<vector<int>>& edges)
    {
        for(auto& it:edges)
        {
            swap(it[0],it[2]);
            swap(it[1],it[2]);
        }
        sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        int mstWt=0;
        for(auto it:edges)
        {
            int wt=it[0];
            int u=it[1];
            int v=it[2];
            if(ds.findUParent(u)!=ds.findUParent(v))
            {
                ds.unionBySize(u,v);
                mstWt+=wt;
            }
        }
        return mstWt;
    }
};
