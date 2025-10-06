// Input:
// n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], threshold = 4
// Output:
// 3
// Explanation:
// The neighboring cities at a threshold = 4 for each city are:
// City 0 -> [City 1, City 2] 
// City 1 -> [City 0, City 2, City 3] 
// City 2 -> [City 0, City 1, City 3] 
// City 3 -> [City 1, City 2] 
// Cities 0 and 3 have 2 neighboring cities at threshold = 4, but we have to return city 3 since it has the greatest number.

int findTheCity(int n,vector<vector<int>>& edges,int threshold)
{
    vector<vector<int>> dist(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++)
    {
        dist[i][i]=0;
    }
    for(auto it:edges)
    {
        dist[it[0]][it[1]]=it[2];
        dist[it[1]][it[0]]=it[2];
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]!=1e9 && dist[k][j]!=1e9)
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
    int city=-1,mini=n;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]<=threshold)
                count++;
        }
        if(count<=mini)
        {
            mini=count;
            city=i;
        }
    }
    return city;
}
