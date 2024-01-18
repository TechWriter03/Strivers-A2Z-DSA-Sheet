// Input: 
// nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 
// 6
// Explanation: 
// The subarray [4,-1,2,1] has the largest sum 6.

int maxSubArray(vector<int>& nums) 
{
    int n=nums.size(),sum=0,maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        maxi=max(maxi,sum);
        if(sum<0)
            sum=0;
    }
    return maxi;
}