// Input: 
// nums = [2,0,2,1,1,0]
// Output: 
// [0,0,1,1,2,2]

void sortColors(vector<int>& nums) 
{
    int n=nums.size();
    int a=0,b=0;
    for(auto it:nums)
    {
        if(it==0) a++;
        else if(it==1) b++;
    }
    for(int i=0;i<n;i++)
    {
        if(i<a) nums[i]=0;
        else if(i>=a && i<(a+b)) nums[i]=1;
        else nums[i]=2; 
    }
}
