// Input: 
// nums = [3,2,3]
// Output: 
// [3]
// Explanation:
// 3 appears more than ⌊ n/3 ⌋ times.

vector<int> majorityElement(vector<int>& nums) 
{
    int c1=0,c2=0,e1=INT_MIN,e2=INT_MIN;
    for(auto it:nums)
    {
        if(c1==0 && it!=e2)
        {
            e1=it;
            c1=1;
        }
        else if(c2==0 && it!=e1)
        {
            e2=it;
            c2=1;
        }
        else if(it==e1) c1++;
        else if(it==e2) c2++;
        else c1--,c2--;
    }
    int cnt1=0,cnt2=0,n=nums.size();
    for(auto it:nums)
    {
        if(it==e1) cnt1++;
        else if(it==e2) cnt2++;
    }
    if(cnt1>(int)(n/3) && cnt2>(int)(n/3))
        return {e1,e2};
    else if(cnt1>(int)(n/3))
        return {e1};
    else if(cnt2>(int)(n/3))
        return {e2};
    return {};
}
