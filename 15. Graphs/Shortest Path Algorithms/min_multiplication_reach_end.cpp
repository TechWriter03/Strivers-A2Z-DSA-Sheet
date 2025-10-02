// Input:
// arr[] = {2, 5, 7}
// start = 3, end = 30
// Output:
// 2
// Explanation:
// Step 1: 3*2 = 6 % 100000 = 6 
// Step 2: 6*5 = 30 % 100000 = 30

int minimumMultiplications(vector<int>& arr,int start,int end)
{
    int mod=1e5;
    vector<int> vis(mod);
    queue<pair<int,int>> q;
    vis[start]=1;
    q.push({0,start});
    while(!q.empty())
    {
        int steps=q.front().first;
        int node=q.front().second;
        q.pop();
        if(node==end)
            return steps;
        for(auto it:arr)
        {
            int num=(it*node)%mod;
            if(!vis[num])
            {
                vis[num]=1;
                q.push({steps+1,num});
            }
        }
    }
    return -1;
}
