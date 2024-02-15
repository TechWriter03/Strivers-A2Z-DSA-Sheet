// Input: 
// piles = [3,6,7,11]
// h = 8
// Output: 
// 4

long countHours(vector<int>& v,int m)
{
    long c=0;
    for(auto it:v)
    {
        if(it<m) c++;
        else if((it%m)!=0) c+=(it/m)+1;
        else c+=(it/m);
    }
    return c;
}
int minEatingSpeed(vector<int>& piles, int h) 
{
    int maxi=-1;
    for(auto it:piles) maxi=max(maxi,it);
    int low=1,high=maxi,mid;
    long hrs;
    while(low<=high)
    {
        mid=(low+high)/2;
        hrs=countHours(piles,mid);
        if(hrs>h) low=mid+1;
        else if(hrs<=h) high=mid-1;
    }
    return low;
}
