// Input: 
// nums = [-1,0,3,5,9,12]
// target = 9
// Output: 
// 4
// Explanation:
// 9 exists in nums and its index is 4

class Solution {
public:
    int binsearch(vector<int>& a,int low,int high,int k)
    {
        if(low<=high)
        {
            int mid=(low+high)/2;
            if(a[mid]==k) return mid;
            else if(a[mid]<k) return binsearch(a,mid+1,high,k);
            else return binsearch(a,low,mid-1,k);
        }
        return-1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binsearch(nums,0,n-1,target);
    }
};
