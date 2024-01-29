// Input: 
// intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: 
// [[1,6],[8,10],[15,18]]
// Explanation: 
// Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    int n=intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    ans.push_back(intervals[0]);
    for(int i=1;i<n;i++)
    {
        if(ans.back()[1]>=intervals[i][0])
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        else
            ans.push_back(intervals[i]);
    }
    return ans;
}
