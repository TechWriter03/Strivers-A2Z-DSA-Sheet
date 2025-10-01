// Input:
// heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output:
// 2
// Explanation:
// The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

int minimumEffortPath(vector<vector<int>>& heights)
{
    int m=heights.size(),n=heights[0].size();
    vector<vector<int>> dist(m,vector<int>(n,1e9));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
    pq.push({0,{0,0}});
    dist[0][0]=0;
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    while(!pq.empty())
    {
        int efforts=pq.top().first;
        int row=pq.top().second.first;
        int col=pq.top().second.second;
        pq.pop();
        if(row==m-1 && col==n-1)
        {
            return dist[m-1][n-1];
        }
        for(int i=0;i<4;i++)
        {
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n)
            {
                int diff=abs(heights[nrow][ncol]-heights[row][col]);
                int maxEfforts=max(diff,efforts);
                if(maxEfforts<dist[nrow][ncol])
                {
                    pq.push({maxEfforts,{nrow,ncol}});
                    dist[nrow][ncol]=maxEfforts;
                }
            }
        }
    }
    return -1;
}
