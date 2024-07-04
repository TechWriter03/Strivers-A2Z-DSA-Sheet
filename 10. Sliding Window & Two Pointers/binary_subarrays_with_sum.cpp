// Input: 
// nums = [1,0,1,0,1]
// goal = 2
// Output: 
// 4

int subarraySum(vector<int>& nums, int k)
{
    int n=nums.size(),left=0,right=0,sum=0,count=0;
    while(right<n)
    {
        sum+=nums[right];
        while(sum>k && left<=right)
        {
            sum-=nums[left];
            left++;
        }
        count+=right-left+1;
        right++;
    }
    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) 
{
    return subarraySum(nums,goal) - subarraySum(nums,goal-1);
}
