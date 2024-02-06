// Input: 
// n=6
// x=5
// a=[3, 4, 7, 8, 8, 10]   
// Output:
// 4 7
// Explanation:
// The floor and ceiling of 'x' = 5 are 4 and 7, respectively.

void ceilvalue(vector<int>& a,int low,int high,int k,int* cl) 
{ 
	if(low<=high)
	{
		int mid=(low+high)/2;
        if(a[mid]>=k)
		{
			*cl=a[mid];
			ceilvalue(a,low,mid-1,k,cl);
		}
		else 
			ceilvalue(a,mid+1,high,k,cl); 
	}
	return ;
}
void floorvalue(vector<int>& a,int low,int high,int k,int* fl) 
{ 
	if(low<=high)
	{
		int mid=(low+high)/2;
        if(a[mid]<=k)
		{
			*fl=a[mid];
			floorvalue(a,mid+1,high,k,fl); 
		}
		else 
			floorvalue(a,low,mid-1,k,fl);
	}
	return ;
}
pair<int,int> getFloorAndCeil(vector<int>& nums,int n,int target) 
{
    int fl=-1,cl=-1;
    floorvalue(nums,0,n-1,target,&fl);
    ceilvalue(nums,0,n-1,target,&cl);
    return {fl,cl};
}
