// Input:
// N = 35
// Output:
// 5 7
// Explanation:
// 5 and 7 are the unique prime factors of 35.

vector<int>AllPrimeFactors(int n)
{
    vector<int>ans;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            ans.push_back(i);
        while(n%i==0)
            n/=i;
    }
    if(n!=1)
        ans.push_back(n);
    return ans;
}
