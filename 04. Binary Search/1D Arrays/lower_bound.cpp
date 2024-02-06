// Input:
// 6
// 1 2 2 3 3 5
// 0
// Output:
// 0
// Explanation:
// Index '0' is the smallest index such that 'arr[0]' is not less than 'x'.

void binsearch(vector<int>& a,int low,int high,int k,int* ans)
{ 
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]>=k) 
		{
			*ans=mid;
			binsearch(a,low,mid-1,k,ans);
		}
		else 
			binsearch(a,mid+1,high,k,ans); 
	}
	return ;
}
int lowerBound(vector<int>& nums,int n,int target) 
{
	int ans=n;
	binsearch(nums,0,n-1,target,&ans);
	return ans;
}
