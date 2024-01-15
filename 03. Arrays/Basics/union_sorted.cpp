// Input: 
// ‘m’ = 5 ‘n’ = 3
// ‘a’ = [1, 2, 3, 4, 6]
// ‘b’ = [2, 3, 5]
// Output: 
// [1, 2, 3, 4, 5, 6]
// Explanation: 
// Common elements in ‘a’ and ‘b’ are: [2, 3]
// Distinct elements in ‘a’ are: [1, 4, 6]
// Distinct elements in ‘b’ are: [5]
// Union of ‘a’ and ‘b’ is: [1, 2, 3, 4, 5, 6]

#include <bits/stdc++.h>
using namespace std;
vector<int> sortedArray(vector<int> a, vector<int> b) 
{
    int m=a.size(),n=b.size(),i=0,j=0;
    vector<int>ans;
    while(i<m && j<n)
    {
        if(a[i]<=b[j])
        {
            if(ans.size()==0 || a[i]!=ans.back())
                ans.push_back(a[i]);
            i++;
        }
        else 
        {
            if(ans.size()==0 || b[j]!=ans.back())
                ans.push_back(b[j]);
            j++;
        }
    }
    while(i<m)
    {
        if(a[i]!=ans.back())
            ans.push_back(a[i]);
        i++;
    }
    while(j<n)
    {
        if(b[j]!=ans.back())
            ans.push_back(b[j]);
        j++;
    }
    return ans;
}

int main() 
{
    int m,n;
    cin>>m>>n;
    vector<int>a,b,c;
    for(int i=0;i<m;i++)
    {
        int ip;
        cin>>ip;
        a.push_back(ip);
    }
    for(int i=0;i<n;i++)
    {
        int ip;
        cin>>ip;
        b.push_back(ip);
    }
    c=sortedArray(a,b);
    for(auto it:c) 
        cout<<it<<" ";
    return 0;
}
