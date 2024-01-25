// Input: 
// x = -123
// Output: 
// -321

int reverse(int x) 
{
    int rev=0,ld;
    while(x!=0)
    {
        ld=x%10;
        if(rev>INT_MAX/10||rev<INT_MIN/10) 
            return 0;
        rev=(rev*10)+ld;
        x/=10;
    }
    return rev;
}
