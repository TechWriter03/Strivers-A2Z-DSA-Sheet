// Input:
// dist[][] = [[0, -1, 2], [1, 0, 1e8], [3, 1, 0]]
// Output:
// [[0, -1, 2], [1, 0, 3], [2, 1, 0]]

void floydWarshall(vector<vector<int>>& dist)
{
    int n=dist.size();
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]!=1e8 && dist[k][j]!=1e8)
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
}
