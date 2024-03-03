// Input: 
// nums = [7,2,5,10,8]
// k = 2
// Output: 
// 18
// Explanation: 
// The best way is to split it into [7,2,5] and [10,8], where 
// the largest sum among the two subarrays is only 18.

int subarray(vector<int>& v,int m)
{
    int sum=0,c=1;
    for(auto it:v)
    {
        sum+=it;
        if(sum>m)
        {
            c++;
            sum=it;
        }
    }
    return c;
}
int splitArray(vector<int>& nums, int k) 
{
    int low=INT_MIN,high=0,mid;
    for(auto it:nums)
    {
        low=max(low,it);
        high+=it;
    }
    while(low<=high)
    {
        mid=(low+high)/2;
        if(subarray(nums,mid)>k)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}
