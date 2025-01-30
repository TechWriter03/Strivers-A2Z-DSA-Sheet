// Input:
// N = 8
// Arr = {4, 2, 4, 5, 2, 3, 3, 1}
// Output:
// {5, 1} 
// Explanation:
// 5 and 1 have odd occurrences.

vector<long long int> twoOddNum(long long int Arr[],long long int N)  
{
    int XOR=0;
    for(int i=0;i<N;i++)
        XOR^=Arr[i];
    int rightmost=(XOR&(XOR-1))^XOR;
    int b1=0,b2=0;
    for(int i=0;i<N;i++)
    {
        if(rightmost&Arr[i])
            b1^=Arr[i];
        else
            b2^=Arr[i];
    }
    return {b1,b2};
}
