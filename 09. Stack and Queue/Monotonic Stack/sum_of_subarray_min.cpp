// Input:
// arr = [3,1,2,4]
// Output:
// 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.

void findNSE(int n,vector<int>& arr,vector<int>& nse)
{
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
        if(st.empty())
            nse[i]=n;
        else
            nse[i]=st.top();
        st.push(i);
    }
}

void findPSEE(int n,vector<int>& arr,vector<int>& psee)
{
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();
        if(st.empty())
            psee[i]=-1;
        else
            psee[i]=st.top();
        st.push(i);
    }
}

int sumSubarrayMins(vector<int>& arr)
{
    int n=arr.size(),mod=1e9+7;
    long long total=0;
    vector<int>psee(n),nse(n);
    findNSE(n,arr,nse);
    findPSEE(n,arr,psee);
    for(int i=0;i<n;i++)
    {
        long long left=i-psee[i],right=nse[i]-i;
        total+=left*right*arr[i];
        total%=mod;
    }
    return total;
}
