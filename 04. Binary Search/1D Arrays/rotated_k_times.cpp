// Input: 
// n = 5
// arr = [3, 4, 5, 1, 2]
// Output: 
// 3 
// Explanation:
// Array [1 ,2, 3, 4, 5] is rotated right '3' times.

int findKRotation(vector<int> &a)
{
    int n=a.size();
    int low=0,high=n-1,mid,ans=INT_MAX,ind=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[low]<=a[mid])
        {
            if(a[low]<ans)
            {
                ind=low;
                ans=a[low];
            }
            low=mid+1;
        }
        else if(a[mid]<=a[high])
        {
            if(a[mid]<ans)
            {
                ind=mid;
                ans=a[mid];
            }
            high=mid-1;
        }
    }    
    return ind;
}
