Two Pointers & Sliding Window :

1. Constant Window
arr , k
left=0,right=k-1;
left++ , right++;

2. Longest subarray / substring where condition [Eg: sum<=k]
// Better Solution
left=0, right=0
while(r<n)
{
    // include 
    sum+=arr[right];
    while(Invalid condition)
    {
        // exclude 
        sum-=arr[left];
        left++;
    }
    if(sum<=k)
        maxLen=max(maxLen,right-left+1);
    right++;
}
// Time Complexity : O(N+N) or O(2N)
// Optimal Solution
for maximum length questions change that inner while to if 
// Time Complexity : O(N)

3. Number of subarrays where condition [Eg: sum=k]
(using pattern 2)
(No of subarrays with sum<=k ) - (No of subarrays with sum<=k-1)

4. Shortest / Minimum Window 
if found valid window then shrink to get answer.
