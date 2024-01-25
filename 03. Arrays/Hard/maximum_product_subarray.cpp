// Input: 
// nums = [2,3,-2,4]
// Output: 
// 6
// Explanation: 
// [2,3] has the largest product 6.

int maxProduct(vector<int>& nums) 
{
    int n=nums.size(),maxi=INT_MIN,prefix=1,suffix=1;
    for(int i=0;i<n;i++)
    {
        prefix*=nums[i];
        suffix*=nums[n-i-1];
        maxi=max(maxi,max(prefix,suffix));
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
    }
    return maxi;
}
