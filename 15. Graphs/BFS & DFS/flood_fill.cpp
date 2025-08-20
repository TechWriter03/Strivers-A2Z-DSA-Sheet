// Input:
// image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output:
// [[2,2,2],[2,2,0],[2,0,1]]
// Explanation:
// From the center of the image with position (sr, sc) = (1, 1) , all pixels connected by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

void dfs(int row,int col,vector<vector<int>>& image,int color,vector<vector<int>>& ans)
{
    int m=image.size(),n=image[0].size();
    ans[row][col]=color;
    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]!=color && image[row][col]==image[nrow][ncol])
            dfs(nrow,ncol,image,color,ans);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int color)
{
    int m=image.size(),n=image[0].size();
    vector<vector<int>> ans=image;
    dfs(sr,sc,image,color,ans);
    return ans;
}
