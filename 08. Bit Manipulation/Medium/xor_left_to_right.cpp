// Input: 
// L = 4
// R = 8 
// Output:
// 8 
// Explanation:
// 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8

int xorN(int n)
{
    if(n%4==0)
        return n;
    else if(n%4==1)
        return 1;
    else if(n%4==2)
        return n+1;
    else if(n%4==3)
        return 0;
}
int findXOR(int l, int r)
{
    return xorN(l-1)^xorN(r);
}
