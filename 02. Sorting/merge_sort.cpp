#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int low,int mid,int high)
{
    vector<int>temp;
    int left=low,right=mid+1;
    while(left<=mid && right<=high)
    {
        if(a[left]<a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(a[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
        a[i]=temp[i-low];

}

void mergeSort(int arr[], int low, int high) 
{
    int mid=(low+high)/2;
    if(low==high) return;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main()
{
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
    mergeSort(v,0,n-1);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}
