#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&arr) 
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
                swap(arr[i],arr[j]);
        }
    }
}

int main() {
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
