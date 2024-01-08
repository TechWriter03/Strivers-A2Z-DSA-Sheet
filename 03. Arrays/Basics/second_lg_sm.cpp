// Input: 
// ‘n’ = 5
// ‘a’ = [1, 2, 3, 4, 5]
// Output: 
// [4, 2]
// The second largest element after 5 is 4, and the second smallest element after 1 is 2.

#include <bits/stdc++.h>
using namespace std;
vector<int> getSecondOrderElements(int n, vector<int> a) 
{
    int max=INT_MIN,min=INT_MAX,smax=INT_MIN,smin=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            smax=max;
            max=a[i];
        }
        else if(a[i]>smax && a[i]<max)
            smax=a[i];
        if(a[i]<min)
        {
            smin=min;
            min=a[i];
        }
        else if(a[i]<smin && a[i]>min)
            smin=a[i];
    }
    return {smax,smin};
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
    vector<int>ans=getSecondOrderElements(n,a) ;
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}
