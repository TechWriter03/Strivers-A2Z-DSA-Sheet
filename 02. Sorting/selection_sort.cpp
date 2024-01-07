#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&arr) 
{
    int n=arr.size(),min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<=arr[min]) 
                min=j;
        }
        swap(arr[i],arr[min]);
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
    selectionSort(v);
    for(auto it:v) 
        cout<<it<<" ";
    return 0;
}
