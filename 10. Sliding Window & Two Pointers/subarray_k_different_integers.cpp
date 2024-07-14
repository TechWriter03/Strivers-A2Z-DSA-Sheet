// Input: 
// nums = [1,2,1,3,4]
// k = 3
// Output: 
// 3
// Explanation: 
// Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

int countSubarrays(vector<int>& nums, int k)
{
    map<int,int>mp;
    int n=nums.size(),left=0,right=0,count=0;
    while(right<n)
    {
        mp[nums[right]]++;
        while(mp.size()>k)
        {
            mp[nums[left]]--;
            if(mp[nums[left]]==0)
                mp.erase(nums[left]);
            left++;
        }
        count+=right-left+1;
        right++;
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) 
{
    return countSubarrays(nums,k) - countSubarrays(nums,k-1);
}