// Input:
// 6 4
// 0 3 4 7 10 9
// Output:
// 3
// Explanation:
// The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. 
// Here distance between cows are 3, 4 and 3 respectively.

bool place(vector<int> &arr, int dist,int k)
{
    int cows=1,last=arr[0];
    for(auto it:arr)
    {
        if(it-last>=dist)
        {
            cows++;
            last=it;
            if(cows==k)
                return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(),arr.end());
    int n=arr.size(),low=1,high=arr[n-1]-arr[0],mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(place(arr,mid,k))
            low=mid+1;
        else
            high=mid-1;
    }
    return high;
}
