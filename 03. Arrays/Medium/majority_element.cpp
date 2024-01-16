// Input: 
// nums = [2,2,1,1,1,2,2]
// Output: 
// 2

int majorityElement(vector<int>& nums) 
{
      int n=nums.size(),ele=nums[0],count=0;
      for(int i=0;i<n;i++)
      {
          if(nums[i]==ele)
              count++;
          else
              count--;
          if(count==0)
          {
              count=1;
              ele=nums[i];
          }
      }
      return ele;
}
