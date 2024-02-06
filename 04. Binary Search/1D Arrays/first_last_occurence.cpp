// Input: 
// nums = [5,7,7,8,8,10]
// target = 8
// Output: 
// [3,4]

void firstoccur(vector<int>& a,int low,int high,int k,int* f) 
{ 
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
    return ;
}
void lastoccur(vector<int>& a,int low,int high,int k,int* l) 
{
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
    return ;
}
vector<int> searchRange(vector<int>& nums, int target) 
{
    int n=nums.size(),first=-1,last=-1;
    firstoccur(nums,0,n-1,target,&first);
    if(first!=-1)
        lastoccur(nums,0,n-1,target,&last);
    return {first,last};
}
