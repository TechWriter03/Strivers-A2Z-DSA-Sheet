// Input:
// n = 16
// Output:
// true
// Explanation:
// 2^4 = 16

bool isPowerOfTwo(int n)
{
    return (n>0 && (n&(n-1))==0);
}
