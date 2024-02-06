// Input:
// 5 7
// 1 4 7 8 10
// Output:
// 3   
// Explanation:
// In the given test case, the lowest value greater than 7 is 8 and 
// is present at index 3 (0-indexed). 

void binsearch(vector<int>& a,int low,int high,int k,int* ans)
{ 
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]>k) 
		{
			*ans=mid;
			binsearch(a,low,mid-1,k,ans);
		}
		else 
			binsearch(a,mid+1,high,k,ans); 
	}
	return ;
}
int upperBound(vector<int>& nums, int target,int n) 
{
	int ans=n;
	binsearch(nums,0,n-1,target,&ans);
	return ans;
}
