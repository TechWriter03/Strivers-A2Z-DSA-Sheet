// Input:
// accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],
//             ["John","johnsmith@mail.com","john00@mail.com"],
//             ["Mary","mary@mail.com"],
//             ["John","johnnybravo@mail.com"]]
// Output:
// [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
//  ["Mary","mary@mail.com"],
//  ["John","johnnybravo@mail.com"]]

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mailMap;
        for(int i=0;i<n;i++)
        {
            int m=accounts[i].size();
            for(int j=1;j<m;j++)
            {
                string mail=accounts[i][j];
                if(mailMap.find(mail)==mailMap.end())
                    mailMap[mail]=i;
                else
                    ds.unionBySize(i,mailMap[mail]);
            }
        }

        vector<vector<string>> merged(n);
        for(auto it:mailMap)
        {
            string mail=it.first;
            int node=ds.findUParent(it.second);
            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            vector<string> mailList=merged[i];
            if(mailList.empty())
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mailList.begin(),mailList.end());
            for(auto it:mailList)
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
