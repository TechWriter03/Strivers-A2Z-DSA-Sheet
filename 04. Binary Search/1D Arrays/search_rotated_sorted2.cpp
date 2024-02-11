// Input: 
// nums = [2,5,6,0,0,1,2]
// target = 0
// Output: 
// true

bool binsearch(vector<int>& a,int low,int high,int t) 
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==t) 
            return true;
        else if(a[low]==a[mid] && a[mid]==a[high])
        {
            low++;
            high--;
        }
        else if(a[low]<=a[mid])
        {
          if(a[low]<=t && t<=a[mid])
              high=mid-1;
          else
              low=mid+1; 
        }
        else if(a[mid]<=a[high])
        {
          if(a[mid]<=t && t<=a[high])
              low=mid+1; 
          else
              high=mid-1;
        } 
    }
    return false;
}
bool search(vector<int>& nums, int target) 
{
    int n=nums.size();
    return binsearch(nums,0,n-1,target);
}
