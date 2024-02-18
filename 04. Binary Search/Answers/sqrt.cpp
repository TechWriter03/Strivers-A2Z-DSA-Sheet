// Input: 
// n = 7
// Output: 
// 2
// Explanation:
// The square root of the number 7 lies between 2 and 3, so the floor value is 2.

int floorSqrt(int n)
{
    long low=1,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(mid*mid<=n)
            low=mid+1;
        else
            high=mid-1;
    }
    return high;
}
