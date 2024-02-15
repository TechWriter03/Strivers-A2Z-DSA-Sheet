// Input: 
// n = 7
// x = 3
// arr = [1, 1, 1, 2, 2, 3, 3]
// Output: 
// 2
// Explanation: 
// Total occurrences of '3' in the array 'arr' is 2.

void firstoccur(vector<int>& a,int low,int high,int k,int* f) 
{
    if (low>high) 
        return ;
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=k) 
        {
            if(a[mid]==k) 
                *f=mid;
            firstoccur(a,low,mid-1,k,f);
        }
        else
            firstoccur(a,mid+1,high,k,f); 
    }
}
void lastoccur(vector<int>& a,int low,int high,int k,int* l) 
{
    if (low>high) 
        return ;
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]<=k) 
        {
            if(a[mid]==k) 
                *l=mid;
            lastoccur(a,mid+1,high,k,l); 
        }
        else
            lastoccur(a,low,mid-1,k,l);
    }
}
int count(vector<int>& arr, int n, int x) 
{
    int first=-1,last=-1;
    firstoccur(arr,0,n-1,x,&first);
    if(first!=-1)
    {
        lastoccur(arr,0,n-1,x,&last);
	    return last-first+1; 
    }
	return 0;
}
