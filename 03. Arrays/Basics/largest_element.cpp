// Input: 
// n = 5
// arr = [1, 2, 3, 4, 5]
// Output: 
// 5

#include <bits/stdc++.h>
using namespace std;
int largestElement(int n, vector<int>& arr) 
{
    int max=*(arr.begin());
    for(auto it:arr) 
        if(it>=max) 
            max=it;
    return max;
}
int main() 
{
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int ip;
        cin>>ip;
        a.push_back(ip);
    }
    cout<<largestElement(n,a);
    return 0;
}
