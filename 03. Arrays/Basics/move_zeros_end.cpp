// Input: 
// nums = [0,1,0,3,12]
// Output: 
// [1,3,12,0,0]

void moveZeroes(vector<int>& nums) 
{
    int n=nums.size(),i=0,j=1;
    while(j<n)
    {
        if(nums[i]!=0)
            i++;
        if(nums[i]==0)
            swap(nums[i],nums[j]);
        j++;
    }
}
