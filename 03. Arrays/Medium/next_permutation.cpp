// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr: 
// [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
// Example 1:
// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:
// Input: nums = [3,2,1]
// Output: [1,2,3]

void nextPermutation(vector<int>& nums) 
{
    int n=nums.size(),ind=-1;
    for(int i=n-1;i>0;i--)
    {
        if(nums[i]>nums[i-1])
        {
            ind=i-1;
            break;
        }
    }
    if(ind==-1)
    {
        reverse(nums.begin(),nums.end());
        return;
    }
    for(int i=n-1;i>ind;i--)
    {
        if(nums[i]>nums[ind])
        {
            swap(nums[i],nums[ind]);
            break;
        }
    }
    reverse(nums.begin()+ind+1,nums.end());
}
