// Input: 
// nums = [4,5,6,7,0,1,2]
// target = 0
// Output: 
// 4

int binsearch(vector<int>& a,int low,int high,int t) 
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==t) 
            return mid;
        else if(a[low]<a[mid])
        {
            if(a[low]<=t && t<=a[mid])
                high=mid-1;
            else
                low=mid+1; 
        }
        else if(a[mid]<a[high])
        {
            if(a[mid]<=t && t<=a[high])
                low=mid+1; 
            else
                high=mid-1;
        }
        else if(a[mid]<t)
            high=mid-1;
        else
            low=mid+1; 
    }
    return -1;
}
int search(vector<int>& nums, int target) 
{
    int n=nums.size();
    return binsearch(nums,0,n-1,target);
}
