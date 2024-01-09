// Input: 
// nums = [1,1,2]
// Output: 
// 2
// nums = [1,2,_]
// Explanation: 
// Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) 
{
    int n=nums.size();
    int i=0,j=1;
    while(j<n)
    {
        if(nums[i]!=nums[j])
        {
            nums[i+1]=nums[j];
            i++;
        }
        j++;
    }
    return i+1;
}

int main() 
{
    int n,ip;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>ip;
        v.push_back(ip);
    }
    int index=removeDuplicates(v);
    for(int j=0;j<index;j++)
        cout<<v[j]<<" ";
    return 0;
}
