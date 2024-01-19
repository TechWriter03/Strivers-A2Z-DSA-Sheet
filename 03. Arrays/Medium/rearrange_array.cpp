// Input: 
// nums = [3,1,-2,-5,2,-4]
// Output: 
// [3,-2,1,-5,2,-4]
// Explanation:
// The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
// The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
// Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect 
// because they do not satisfy one or more conditions. 

vector<int> rearrangeArray(vector<int>& nums) 
{
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
