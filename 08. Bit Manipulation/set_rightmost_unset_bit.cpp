// Input:
// n = 6
// Output:
// 7
// Explanation:
// The binary representation of 6 is 110.
// After setting right most bit it becomes 111 which is 7.

int setBit(int n)
{
    return n|(n+1);
}
