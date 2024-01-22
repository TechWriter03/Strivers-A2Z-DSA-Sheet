// Note:
// The last element of the array is always a Superior Element. 
// Input:
// n=4
// a = [1, 2, 3, 2]
// Output: 
// 2 3
// Explanation: 
// 3 is greater than 2. 
// 2 is the last element.

vector<int> superiorElements(vector<int>& arr) 
{
    int n=arr.size(),maxi=INT_MIN;
    vector<int>ans;
    ans.push_back(arr[n-1]);
    for(int i=n-1;i>=0;i--)
    {
        maxi=max(maxi,arr[i]);
        if(arr[i]>=maxi && find(ans.begin(),ans.end(),arr[i])==ans.end())
            ans.push_back(arr[i]);
    }
    return ans;
}
