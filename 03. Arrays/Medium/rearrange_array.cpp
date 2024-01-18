class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int posInd=0,negInd=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[posInd]=nums[i];
                posInd+=2;
            }
            else
            {
                ans[negInd]=nums[i];
                negInd+=2;
            }
        }
        return ans;
    }
};