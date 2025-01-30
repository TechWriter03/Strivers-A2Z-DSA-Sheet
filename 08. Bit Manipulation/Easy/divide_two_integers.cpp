// Input:
// dividend = 10
// divisor = 3
// Output:
// 3
// Explanation:
// 10/3 = 3.33333.. which is truncated to 3.

int divide(int dividend, int divisor)
{
    if(dividend==INT_MIN && divisor==-1)
        return INT_MAX;
    if(dividend==divisor)
        return 1;
    bool sign=true;
    if(dividend>=0 && divisor<0)
        sign=false;
    if(dividend<0 && divisor>=0)
        sign=false;
    long n=labs(dividend),d=labs(divisor),quotient=0;
    while(n>=d)
    {
        int p=0;
        while((d<<(p+1))<n)
            p++;
        quotient+=(1<<p);
        n-=d*(1<<p);
    }
    if(quotient==(1<<31) && sign)
        return INT_MAX;
    return sign?quotient:-quotient;
}
