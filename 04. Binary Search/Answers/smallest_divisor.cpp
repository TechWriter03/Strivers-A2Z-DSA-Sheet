// Input: 
// nums = [1,2,5,9]
// threshold = 6
// Output: 
// 5
// Explanation: 
// We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).

int check(vector<int>& v,int m)
{
    int c=0;
    for(auto it:v)
    {
        if(it<=m && it>0) c++;
        else if((it%m)!=0) c+=(it/m)+1;
        else c+=(it/m);
    }
    return c;
}
int smallestDivisor(vector<int>& nums, int th) 
{
    int low=1,high=INT_MIN,mid;
    for(auto it:nums) high=max(high,it);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(check(nums,mid)<=th) high=mid-1;
        else low=mid+1;
    }
    return low;
}
