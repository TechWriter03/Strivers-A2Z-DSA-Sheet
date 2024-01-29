// Input: 
// nums = [1,0,-1,0,-2,2]
// target = 0
// Output: 
// [[-2,-1,1,2],
//  [-2,0,0,2],
//  [-1,0,0,1]]

vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    vector<vector<int>>ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int x=0;x<=n-4;x++)
    {
        if(x>0 && nums[x]==nums[x-1])
            continue;
        for(int i=x+1;i<=n-3;i++)
        {
            if(i>x+1 && nums[i]==nums[i-1])
                continue;
            int j=i+1,k=n-1;
            while(j<k)
            {
                long sum=nums[x]+nums[i];
                sum+=nums[j]+nums[k];
                if(sum<target)
                    j++;
                else if(sum>target) 
                    k--;
                else
                {
                    ans.push_back({nums[x],nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                        j++;
                    while(j<k && nums[k]==nums[k+1])
                        k--;
                }
            }
        }
    }
    return ans;
}
