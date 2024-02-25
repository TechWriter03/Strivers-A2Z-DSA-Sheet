// Input: arr = [2,3,4,7,11]
// k = 5
// Output: 
// 9
// Explanation: 
// The missing positive integers are [1,5,6,8,9,10,...]. 
// The 5th missing positive integer is 9.

int findKthPositive(vector<int>& arr, int k) 
{
    int n=arr.size(),low=0,high=n-1,mid,mis;
    while(low<=high)
    {
        mid=(low+high)/2;
        mis=arr[mid]-(mid+1);
        if(mis<k) 
            low=mid+1;
        else 
            high=mid-1;
    }
    return k+low;
}
