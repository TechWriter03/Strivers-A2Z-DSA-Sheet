// Input :
// n=4 
// k=2
// [10,20,30,40]
// Output :
// 60
// Explanation :
// we can divide the first 3 boards for one painter and the last board for the second painter.

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
