// Input: 
// n = 4 
// m = 2 
// arr = [12, 34, 67, 90]
// Output: 
// 113
// Explanation: 
// All possible ways to allocate the ‘4’ books to '2' students are:
// 12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, 
// and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.
// 12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, 
// and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.
// 12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, 
// and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.
// We are getting the minimum in the last case.
// Hence answer is ‘113’.

int allocate(vector<int>& v,int m)
{
    int pages=0,stu=1;
    for(auto it:v)
    {
        pages+=it;
        if(pages>m)
        {
            stu++;
            pages=it;
        }
    }
    return stu;
}

int findPages(vector<int>& nums,int n, int k) 
{
    int low=INT_MIN,high=0,mid;
    if(k>n)
        return -1;
    for(auto it:nums)
    {
        low=max(low,it);
        high+=it;
    }
    while(low<=high)
    {
        mid=(low+high)/2;
        if(allocate(nums,mid)>k)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}
