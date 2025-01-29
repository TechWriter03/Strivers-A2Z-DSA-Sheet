// Input:
// nums = [4,1,2,1,2]
// Output:
// 4

int singleNumber(vector<int>& nums)
{
    int result=0;
    for(auto it:nums)
        result^=it;
    return result;
}
