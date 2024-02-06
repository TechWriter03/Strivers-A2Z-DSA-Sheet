// Given a sorted array of distinct integers and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.
// Input: 
// nums = [1,3,5,6]
// target = 5
// Output: 
// 2

void binsearch(vector<int>& a,int low,int high,int k,int* ans)
{ 
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=k) 
        {
            *ans=mid;
            binsearch(a,low,mid-1,k,ans);
        }
        else 
            binsearch(a,mid+1,high,k,ans); 
    }
    return ;
}
int searchInsert(vector<int>& nums, int target) 
{
    int n=nums.size(),ans=n;
    binsearch(nums,0,n-1,target,&ans);
    return ans;
}
