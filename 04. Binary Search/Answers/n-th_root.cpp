// Input: 
// n = 3
// m = 27
// Output: 
// 3
// Explanation: 
// 3rd Root of 27 is 3, as (3)^3 equals 27.

int pow_n(int mid,int n,int m)
{
    long long p=1;
    for(int i=1;i<=n;i++)
    {
        p*=mid;
        if(p>m) return 2;
    }
    if(p<m) return 0;
    if(p==m) return 1;
}
int NthRoot(int n, int m) 
{
    int low=1,high=m,mid,val;
    while(low<=high)
    {
        mid=(low+high)/2;
        val=pow_n(mid,n,m);
        if(val==1) return mid;
        else if(val==2) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
