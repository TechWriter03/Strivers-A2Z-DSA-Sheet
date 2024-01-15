#include<bits/stdc++.h>
using namespace std;
int partitionArray(int input[], int start, int end) 
{
	int pivot=input[start];
	int i=start,j=end;
	while(i<j)
	{
		while(input[i]<=pivot && i<=end)
			i++;
		while(input[j]>pivot && j>=start+1)
			j--;
    	if(i<j)
			swap(input[i],input[j]);
	}
	swap(input[start],input[j]);
	return j;
}

void quickSort(int input[], int start, int end) 
{
	int pInd;
	if(start<end)
	{
		pInd=partitionArray(input,start,end);
		quickSort(input,start,pInd-1);
		quickSort(input,pInd+1,end);
	}
}

int main()
{
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
    quickSort(v,0,n-1);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    return 0;
}
