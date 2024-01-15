// Input: 
// nums = [2,7,11,15]
// target = 9
// Output: 
// [0,1]
// Explanation: 
// Because nums[0] + nums[1] == 9, we return [0, 1].

vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++)
    {
        int rem=target-nums[i];
        if(mp.find(rem)!=mp.end())
            return {mp[rem],i};
        mp[nums[i]]=i;
    }
}
