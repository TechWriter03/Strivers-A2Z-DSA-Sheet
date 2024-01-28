// Input: 
// nums = [-1,0,1,2,-1,-4]
// Output: 
// [[-1,-1,2],[-1,0,1]]

vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>>ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<=n-3;i++)
    {
        if(i>0 && nums[i]==nums[i-1])
            continue;
        int j=i+1,k=n-1,sum;
        while(j<k)
        {
            sum=nums[i]+nums[j]+nums[k];
            if(sum<0)
                j++;
            else if(sum>0) 
                k--;
            else
            {
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])
                    j++;
                while(j<k && nums[k]==nums[k+1])
                    k--;
            }
        }
    }
    return ans;
}
