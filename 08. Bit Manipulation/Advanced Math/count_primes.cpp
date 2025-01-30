// Input:
// n = 10
// Output:
// 4
// Explanation:
// There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

int countPrimes(int n)
{
    int count=0;
    vector<int> primes(n,1);
    for(int i=2;i*i<n;i++)
    {
        if(primes[i])
        {
            for(int j=i*i;j<n;j+=i)
                primes[j]=0;
        }
    }
    for(int i=2;i<n;i++)
        count+=primes[i];
    return count;
}
