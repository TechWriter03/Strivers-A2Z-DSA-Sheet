// Input:
// N = 4
// m = 
// [[1, 0, 0, 0],
//  [1, 1, 0, 1], 
//  [1, 1, 0, 0],
//  [0, 1, 1, 1]]
// Output:
// DDRDRR DRDDRR  
// Explanation:
// The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

void findPaths(int n,vector<vector<int>>& m,int row,int col,string path,vector<string>& ans,vector<vector<bool>>& visited)
{
    if(row==n-1 && col==n-1)
    {
        if(m[row][col]!=0)
        {
            ans.push_back(path);
            return;
        }
    }
    if(row<0 || col<0 || row>=n || col>=n)
        return;
    if(m[row][col]==0 || visited[row][col])
        return;
    
    visited[row][col]=true;
    
    findPaths(n,m,row-1,col,path+"U",ans,visited);
    findPaths(n,m,row+1,col,path+"D",ans,visited);
    findPaths(n,m,row,col-1,path+"L",ans,visited);
    findPaths(n,m,row,col+1,path+"R",ans,visited);
    
    visited[row][col]=false;
    
    return;
}

vector<string> findPath(vector<vector<int>>& m, int n)
{
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    findPaths(n,m,0,0,"",ans,visited);
    if(ans.size()==0)
        ans.push_back("-1");
    return ans;
}
