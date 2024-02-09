// Input: 
// nums = [1,1,2,3,3,4,4,8,8]
// Output: 
// 2


int find(vector<int>& a,int low,int high)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1])
            return a[mid];
        else if((mid%2==0 && a[mid]!=a[mid+1])||(mid%2==1 && a[mid]!=a[mid-1]))
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
int singleNonDuplicate(vector<int>& nums) 
{
    int n=nums.size();
    if(n==1) return nums[0];
    else if(nums[0]!=nums[1]) return nums[0];
    else if(nums[n-2]!=nums[n-1]) return nums[n-1]; 
    else return find(nums,1,n-2);
}
