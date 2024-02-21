// Input: 
// weights = [1,2,3,4,5,6,7,8,9,10]
// days = 5
// Output: 
// 15
// Explanation: 
// A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10
// Note: The cargo must be shipped in the order given.

int calc(vector<int>& v,int m)
{
    int wt=0,d=1;
    for(auto it:v)
    {
        wt+=it;
        if(wt>m)
        {
            d++;
            wt=it;
        }
    }
    return d;
}
int shipWithinDays(vector<int>& weights, int days) 
{
    int low=INT_MIN,high=0,mid;
    for(auto it:weights)
    {
        low=max(low,it);
        high+=it;
    }
    while(low<=high)
    {
        mid=(low+high)/2;
        if(calc(weights,mid)<=days) high=mid-1;
        else low=mid+1;
    }
    return low;
}
