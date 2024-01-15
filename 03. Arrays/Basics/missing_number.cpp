// Input: 
// nums = [3,0,1]
// Output: 
// 2
// Explanation: 
// n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
// 2 is the missing number in the range since it does not appear in nums.

int missingNumber(vector<int>& nums) 
{
    int n=nums.size();
    int og_sum=(n*(n+1))/2;
    int sum=0;
    for(auto it:nums)
        sum+=it;
    return og_sum-sum;
}
