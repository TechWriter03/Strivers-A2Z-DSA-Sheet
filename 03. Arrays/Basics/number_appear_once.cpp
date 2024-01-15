// Input: 
// nums = [4,1,2,1,2]
// Output: 
// 4

int singleNumber(vector<int>& nums) 
{
    int XOR=nums[0];
    for(int i=1;i<nums.size();i++)
        XOR^=nums[i];
    return XOR;
}
