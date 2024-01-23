// Input: 
// nums = [1,2,3]
// k = 3
// Output: 
// 2

int subarraySum(vector<int>& a, int k) 
{
    int n=a.size(),preSum=0,count=0,rem;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        preSum+=a[i];
        if(preSum==k)
            count++;
        rem=preSum-k;
        if(mp.find(rem)!=mp.end())
            count+=mp[rem];
        mp[preSum]++;
    }
    return count;
}
