// Input: 
// m = 3
// nums1 = [1,2,3,0,0,0]
// n = 3
// nums2 = [2,5,6]
// Output: 
// [1,2,2,3,5,6]
// Explanation: 
// The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

void swapping(vector<int>& a,vector<int>& b,int x,int y)
{
    if(a[x]>b[y])
        swap(a[x],b[y]);
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int len=m+n,gap=(len/2)+(len%2);
    while(gap>0)
    {
        int left=0,right=left+gap;
        while(right<len)
        {
            if(left<m && right<m)
                swapping(nums1,nums1,left,right);
            else if(left>=m)
                swapping(nums2,nums2,left-m,right-m);
            else
                swapping(nums1,nums2,left,right-m);
            left++;
            right++;
        }
        if(gap==1)
            break;
        gap=(gap/2)+(gap%2);
    }
    for(int i=0;i<n;i++)
        nums1[i+m]=nums2[i];
}
