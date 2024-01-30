class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size(),c=0,l=n-k;
        int i=0,j=k-1;
        long sum=0;
        for(int x=i;x<=j;x++) sum+=arr[x];
        if(sum/k>=threshold) c++;
        while(i<=l && j<n-1)
        {
            j++;
            sum+=arr[j];
            sum-=arr[i];
            i++;
            if(sum/k>=threshold) c++;
        }
        return c;
    }
};