// Input:
// a = 13
// b = 9
// Output:
// 9 13
// Explanation:
// After swapping it becomes 9 and 13.

pair<int,int> swap(int a,int b)
{
    a=a^b;
    b=a^b;
    a=a^b;
    return {a,b};
}
