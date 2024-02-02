// Input: 
// nums = [1,3,2,3,1]
// Output: 
// 2
// Explanation: 
// The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

int countpairs(vector<int>& a,int low,int mid,int high) 
{
    int count=0,right=mid+1;
    for(int i=low;i<=mid;i++)
    {
        while(right<=high && a[i]>2LL*a[right])
            right++;
        count+=right-(mid+1);
    }
    return count;
}
void merge(vector<int>& a,int low,int mid,int high) 
{
    vector<int>temp;
    int left=low,right=mid+1;
    while(left<=mid && right<=high)
    {
        if(a[left]<=a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(a[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
        a[i]=temp[i-low];
}
int mergesort(vector<int>& a,int low,int high) 
{
    int count=0;
    if(low<high)
    {
        int mid=(low+high)/2;
        count+=mergesort(a,low,mid);
        count+=mergesort(a,mid+1,high);
        count+=countpairs(a,low,mid,high);
        merge(a,low,mid,high);
    }
    return count;
}
int reversePairs(vector<int>& nums) 
{
    int n=nums.size();
    return mergesort(nums,0,n-1);
}
