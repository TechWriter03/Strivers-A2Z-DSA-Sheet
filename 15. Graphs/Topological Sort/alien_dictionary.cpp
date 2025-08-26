// Input:
// words[] = ["caa", "aaa", "aab"]
// Output:
// true
// Explanation:
// A possible correct order of letters in the alien dictionary is "cab".
// The pair "caa" and "aaa" suggests 'c' appears before 'a'.
// The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
// So, 'c' → 'a' → 'b' is a valid ordering.

int markPresent(vector<string> words,vector<int>& present)
{
    int count=0;
    for(auto it:words)
    {
        for(auto ch:it)
        {
            if(!present[ch-'a'])
            {
                count++;
                present[ch-'a']=1;
            }
        }
    }
    return count;
}

bool createGraph(string s1,string s2,vector<vector<int>>& adj)
{
    int i=0,j=0,m=s1.size(),n=s2.size();
    while(i<m && j<n)
    {
        if(s1[i]!=s2[j])
        {
            adj[s1[i]-'a'].push_back(s2[j]-'a');
            return true;
        }
        i++;
        j++;
    }
    if(m>n)
        return false;
    return true;
}

string topoSort(int V,vector<vector<int>>& adj,vector<int>& present,int k)
{
    vector<int> indegree(V);
    for(auto it:adj)
    {
        for(auto i:it)
        {
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(present[i] && indegree[i]==0)
            q.push(i);
    }
    string topoSort="";
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topoSort+=(node+'a');
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    if(topoSort.size()==k)
        return topoSort;
    return "";
}

string findOrder(vector<string> &words)
{
    int n=words.size();
    vector<vector<int>> adj(26);
    vector<int> present(26);
    int k=markPresent(words,present);
    for(int i=0;i<n-1;i++)
    {
        if(!createGraph(words[i],words[i+1],adj))
            return "";
    }
    return topoSort(26,adj,present,k);
}
