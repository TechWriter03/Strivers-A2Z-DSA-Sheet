// Input:
// s = "tree"
// Output:
// "eert"
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

string frequencySort(string s)
{
    string ans="";
    unordered_map<char,int>mp1;
    for(auto it:s)
        mp1[it]++;
    map<int,vector<char>>mp2;
    for(auto it:mp1)
        mp2[it.second].push_back(it.first);
    for(auto it=mp2.rbegin();it!=mp2.rend();it++)
    {
        for(auto itr:it->second)
            for(int i=0;i<it->first;i++)
                ans+=itr;
    }
    return ans;
}
