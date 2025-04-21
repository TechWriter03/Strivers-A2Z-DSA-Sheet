// Input:
// height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output:
// 6
// Explanation:
// The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
// In this case, 6 units of rain water (blue section) are being trapped.

int trap(vector<int>& height)
{
    int n=height.size(),left=0,right=n-1,lmax=0,rmax=0,total=0;
    while(left<right)
    {
        if(height[left]<=height[right])
        {
            if(height[left]>lmax)
                lmax=height[left];
            else
                total+=lmax-height[left];
            left++;
        }
        else
        {
            if(height[right]>rmax)
                rmax=height[right];
            else
                total+=rmax-height[right];
            right--;
        }
    }
    return total;
}
