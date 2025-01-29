// Input:
// 8 1
// Output:
// 0 9 8
// Explanation:
// Bit at the first position from LSB is 0 (1 0 0 0).
// The value of the given number after setting the 1st bit is 9 (1 0 0 1).
// The value of the given number after clearing 1st bit is 8 (1 0 0 0).

void bitManipulation(int num, int i)
{
    i--;
    int ithBit=(num&(1<<i))!=0;
    cout<<ithBit<<" ";
    int set_ithBit=num|(1<<i);
    cout<<set_ithBit<<" ";
    int clear_ithBit=num&(~(1<<i));
    cout<<clear_ithBit;
}
