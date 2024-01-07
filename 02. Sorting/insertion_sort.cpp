#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            int t=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=t;
            j--;
        }
    }
}

int main() 
{
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
    insertionSort(v,n);
    for(auto it:v) 
        cout<<it<<" ";
    return 0;
}
