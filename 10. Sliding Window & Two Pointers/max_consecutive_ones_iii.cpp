// Input: 
// nums = [1,1,1,0,0,0,1,1,1,1,0]
// k = 2
// Output: 
// 6
// Explanation: 
// [1,1,1,0,0,1,1,1,1,1,1]

int longestOnes(vector<int>& nums, int k) 
{
    int n=nums.size(),left=0,right=0,zeros=0,maxLen=0;
    while(right<n)
    {
        if(nums[right]==0)
            zeros++;
        if(zeros>k)
        {
            if(nums[left]==0)
                zeros--;
            left++;
        }
        int len=right-left+1;
        maxLen=max(maxLen,len);
        right++;
    }  
    return maxLen;  
}
