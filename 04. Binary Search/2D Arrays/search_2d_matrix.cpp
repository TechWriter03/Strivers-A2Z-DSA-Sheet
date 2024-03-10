// Input: 
// matrix =
// [[1,3,5,7],
//  [10,11,16,20],
//  [23,30,34,60]]
// target = 3
// Output: 
// true

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m=matrix.size(),n=matrix[0].size();
    int low=0,high=(m*n)-1,mid,row,col,ele;
    while(low<=high)
    {
        mid=(low+high)/2;
        row=mid/n;
        col=mid%n;
        ele=matrix[row][col];
        if(ele==target)
            return true;
        else if(ele<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return false;
}
