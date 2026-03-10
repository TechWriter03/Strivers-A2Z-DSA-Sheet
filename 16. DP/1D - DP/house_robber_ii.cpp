class Solution
{
public:
    int findMax(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int prev2=nums[0],prev1=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int curr=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> nums1,nums2;
        for(int i=0;i<n;i++)
        {
            if(i>0)
                nums1.push_back(nums[i]);
            if(i<n-1)
                nums2.push_back(nums[i]);
        }
        int result1=findMax(nums1);
        int result2=findMax(nums2);
        return max(result1,result2);
    }
};