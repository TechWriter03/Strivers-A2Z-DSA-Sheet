// Input:
// n = 5, nums[] = [1, 2, 5, 3, 2]
// Output:
// 5
// Explanation:
// The sequence [1, 2, 5] is increasing and the sequence [3, 2] is decreasing so merging both we will get length 5.

int longestBitonicSequence(int n,vector<int>& nums)
{
    vector<int> dp1(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i]>nums[j] && dp1[i]<dp1[j]+1)
                dp1[i]=dp1[j]+1;
        }
    }

    int maxi=0;
    vector<int> dp2(n,1);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(nums[i]>nums[j] && dp2[i]<dp2[j]+1)
                dp2[i]=dp2[j]+1;
        }
        if(dp1[i]>1 && dp2[i]>1)
            maxi=max(dp1[i]+dp2[i]-1,maxi);
    }

    return maxi;
}
