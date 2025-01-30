// Input :
// 20
// Output:
// 1 2 4 5 10 20
// Explanation:
// 20 is completely divisible by 1, 2, 4, 5, 10 and 20.

void print_divisors(int n)
{
    for(int i=1;i*i<=n;i++)
        if(n%i==0)
            cout<<i<<" "<<n/i<<" ";
}
