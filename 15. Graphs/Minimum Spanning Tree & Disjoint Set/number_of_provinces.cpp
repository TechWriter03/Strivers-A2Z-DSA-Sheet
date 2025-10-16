// Input:
// graph = [[1,1,0],[1,1,0],[0,0,1]]
// Output:
// 2

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
    int findCircleNum(vector<vector<int>>& graph)
    {
        int n=graph.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]==1)
                    ds.unionBySize(i,j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
                count++;
        }
        return count;
    }
};
