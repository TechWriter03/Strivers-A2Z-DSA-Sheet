// Input:
// 6
// Output:
// 4
// Explanation:
// The binary representation of 6 is 110.
// After clearing right most bit it becomes 100 which is 4.

int unsetBit(int n)
{
    return n&(n-1);
}
