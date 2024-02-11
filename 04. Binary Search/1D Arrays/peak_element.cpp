// Input: 
// nums = [1,2,1,3,5,6,4]
// Output: 
// 5
// Explanation: 
// Your function can return either index number 1 where the peak element is 2, 
// or index number 5 where the peak element is 6.

int findPeakElement(vector<int>& a) 
{
    int n=a.size();
    if(n==1 || a[0]>a[1]) 
        return 0;
    if(a[n-1]>a[n-2]) 
        return n-1;
    int low=1,high=n-2,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
            return mid;
        else if(a[mid]<a[mid+1] && a[mid]>a[mid-1])
            low=mid+1;
        else if(a[mid]>a[mid+1] && a[mid]<a[mid-1])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
