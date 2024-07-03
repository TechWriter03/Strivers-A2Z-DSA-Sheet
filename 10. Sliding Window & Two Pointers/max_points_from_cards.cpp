// Input: 
// points = [1,2,3,4,5,6,1]
// k = 3
// Output: 
// 12

int maxScore(vector<int>& points, int k) 
{
    int n=points.size(),leftSum=0,rightSum=0,maxPoints=0;
    for(int i=0;i<k;i++)
    {
        leftSum+=points[i];
        maxPoints=max(maxPoints,leftSum);
    }
    int left=k-1,right=n-1;
    while(right>n-1-k)
    {
        leftSum-=points[left];
        left--;
        rightSum+=points[right];
        right--;
        int sum=leftSum+rightSum;
        maxPoints=max(maxPoints,sum);
    }
    return maxPoints;
}
