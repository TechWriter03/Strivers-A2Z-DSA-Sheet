// Input: 
// ‘n’ = 7 
// ‘k’ = 3
// ‘a’ = [1, 2, 3, 1, 1, 1, 1]
// Output: 
// 3
// Explanation: 
// Subarrays whose sum = ‘3’ are,
// [1, 2], [3], [1, 1, 1] and [1, 1, 1]
// Here, the length of the longest subarray is 3, which is our final answer.

int longestSubarrayWithSumK(vector<int> a, long long k) 
{
    long long sum=0;
    int len=0,i=0,j=0;
    while(j<a.size())
    {
        sum+=a[j];
        while(sum>k)
        {
            sum-=a[i];
            i++;
        }
        if(sum==k)
            len=max(len,j-i+1);
        j++;
    }
    return len;
}
