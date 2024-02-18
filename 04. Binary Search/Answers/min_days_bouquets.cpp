// Input: 
// bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
// Output: 
// 12
// Explanation: 
// We need 2 bouquets each should have 3 flowers.
// Here is the garden after the 7 and 12 days:
// After day 7: [x, x, x, x, _, x, x]
// We can make one bouquet of the first three flowers that bloomed. 
// We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
// After day 12: [x, x, x, x, x, x, x]
// It is obvious that we can make two bouquets in different ways.

int flowers(vector<int>& bloomDay,int mid,int k)
{
    int tot=0,c=0;
    for(auto it:bloomDay)
    {
        if(it<=mid) 
            c++;
        else
        {
            tot+=(c/k);
            c=0;
        }
    }
    tot+=(c/k);
    return tot;
}
int minDays(vector<int>& bloomDay, int m, int k) 
{
    int n=bloomDay.size();
    if(n<(long long)m*k) 
        return -1;
    int maxi=INT_MIN,mini=INT_MAX;
    for(auto it:bloomDay)
    {
        maxi=max(maxi,it);
        mini=min(mini,it);
    }
    int low=mini,high=maxi,mid,flo;
    while(low<=high)
    {
        mid=(low+high)/2;
        flo=flowers(bloomDay,mid,k);
        if(flo>=m) 
            high=mid-1;
        else 
            low=mid+1;
    }
    return low;
}
