// Input:
// nums = [1,2,3]
// Output:
// 4
// Explanation:
// The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0 
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

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

long long SubArrayMins(vector<int>& arr)
{
    int n=arr.size();
    long long total=0;
    vector<int>psee(n),nse(n);
    findNSE(n,arr,nse);
    findPSEE(n,arr,psee);
    for(int i=0;i<n;i++)
    {
        long long left=i-psee[i],right=nse[i]-i;
        total+=left*right*arr[i];
    }
    return total;
}

void findNGE(int n,vector<int>& arr,vector<int>& nge)
{
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]<=arr[i])
            st.pop();
        if(st.empty())
            nge[i]=n;
        else
            nge[i]=st.top();
        st.push(i);
    }
}

void findPGEE(int n,vector<int>& arr,vector<int>& pgee)
{
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]<arr[i])
            st.pop();
        if(st.empty())
            pgee[i]=-1;
        else
            pgee[i]=st.top();
        st.push(i);
    }
}

long long SubArrayMaxs(vector<int>& arr)
{
    int n=arr.size();
    long long total=0;
    vector<int>pgee(n),nge(n);
    findNGE(n,arr,nge);
    findPGEE(n,arr,pgee);
    for(int i=0;i<n;i++)
    {
        long long left=i-pgee[i],right=nge[i]-i;
        total+=left*right*arr[i];
    }
    return total;
}

long long subArrayRanges(vector<int>& nums)
{
    return SubArrayMaxs(nums)-SubArrayMins(nums);
}
