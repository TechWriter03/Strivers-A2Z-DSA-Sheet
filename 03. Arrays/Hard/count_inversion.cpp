// Input:
// N = 5
// A = [5, 3, 2, 1, 4]
// Output:
// 7
// Explanation: 
// The pairs satisfying the condition for inversion are 
// (1, 2), (1, 3), (1, 4), (1, 5), (2, 3), (2, 4), and (3, 4). 
// The number of inversions in the array is 7.

void merge(vector<int>& a,int low,int mid,int high,int* count)
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
            *count+=mid-left+1;
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
void mergesort(vector<int>& a,int low,int high,int* count)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid,count);
        mergesort(a,mid+1,high,count);
        merge(a,low,mid,high,count);
    }
    return ;
}
int numberOfInversions(vector<int>&a, int n) 
{
    int count=0;
    mergesort(a,0,n-1,&count);
    return count;
}
