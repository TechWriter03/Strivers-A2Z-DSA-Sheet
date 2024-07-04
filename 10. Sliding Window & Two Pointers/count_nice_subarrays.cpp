// Input:
// nums = [1,1,2,1,1]
// k = 3
// Output:
// 2
// Explanation:
// The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

int niceSubarrayLessThanK(vector<int>& nums, int k)
{
    int n=nums.size(),left=0,right=0,odds=0,count=0;
    while(right<n)
    {
        if(nums[right]%2)
            odds++;
        while(odds>k && left<=right)
        {
            if(nums[left]%2)
                odds--;
            left++;
        }
        count+=right-left+1;
        right++;
    }
    return count;
}
int numberOfSubarrays(vector<int>& nums, int k) 
{
    return niceSubarrayLessThanK(nums,k) - niceSubarrayLessThanK(nums,k-1);
}
