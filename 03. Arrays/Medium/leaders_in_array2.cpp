// Input: 
// arr = [17,18,5,4,6,1]
// Output: 
// [18,6,6,6,1,-1]
// Explanation: 
// - index 0 --> the greatest element to the right of index 0 is 18.
// - index 1 --> the greatest element to the right of index 1 is 6.
// - index 2 --> the greatest element to the right of index 2 is 6.
// - index 3 --> the greatest element to the right of index 3 is 6.
// - index 4 --> the greatest element to the right of index 4 is 1.
// - index 5 --> there are no elements to the right of index 5, so we put -1.

vector<int> replaceElements(vector<int>& arr) 
{
    int n=arr.size(),maxi=INT_MIN;
    arr.push_back(-1);
    for(int i=n-1;i>=0;i--)
    {
        maxi=max(maxi,arr[i]);
        if(maxi>arr[i])
            arr[i]=maxi;
    }
    arr.erase(arr.begin());
    return arr;
}
