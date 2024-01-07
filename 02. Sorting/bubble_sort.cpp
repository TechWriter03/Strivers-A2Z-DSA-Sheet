#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&arr) 
{
    int n=arr.size(),didSwap;
    for(int i=0;i<n-1;i++)
    {
        didSwap=0;
        for(int j=i;j<n-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(arr[j],arr[j+1]);
                didSwap=1;
            }
        }
        if(didSwap==0)
            break;
    }
}

int main() 
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        v.push_back(m);
    }
    bubbleSort(v);
    for(auto it:v) 
        cout<<it<<" ";
    return 0;
}
