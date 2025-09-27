// Input:
// beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output:
// [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation:
// There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"

// Interview oriented solution (MLE)
vector<vector<string>> findLadders(string beginWord,string endWord,vector<string>& wordList)
{
    vector<vector<string>> ans;
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    vector<string> used;
    q.push({beginWord});
    st.erase(beginWord);
    int level=1;
    while(!q.empty())
    {
        vector<string> seq=q.front();
        q.pop();
        if(seq.size()>level)
        {
            level++;
            for(auto it:used)
            {
                st.erase(it);
            }
        }
        string word=seq.back();
        if(word==endWord)
        {
            if(ans.empty())
            {
                ans.push_back(seq);
            }
            else if(ans[0].size()==seq.size())
            {
                ans.push_back(seq);
            }
        }
        for(int i=0;i<word.size();i++)
        {
            char original=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.find(word)!=st.end())
                {
                    used.push_back(word);
                    seq.push_back(word);
                    q.push(seq);
                    seq.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;
}

// CP Solution (Accepted)
class Solution
{
private:
    vector<vector<string>> ans;
    unordered_map<string,int> mp;

    void dfs(string word,string beginWord,vector<string>& seq)
    {
        if(word==beginWord)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int level=mp[word];
        for(int i=0;i<word.size();i++)
        {
            char original=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(mp[word]==level-1)
                {
                    seq.push_back(word);
                    dfs(word,beginWord,seq);
                    seq.pop_back();
                }
            }
            word[i]=original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord,string endWord,vector<string>& wordList)
    {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        mp[beginWord]=1;
        while(!q.empty())
        {
            string word=q.front();
            q.pop();
            if(word==endWord)
            {
                break;
            }
            for(int i=0;i<word.size();i++)
            {
                int level=mp[word];
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push(word);
                        mp[word]=level+1;
                    }
                }
                word[i]=original;
            }
        }
        if(mp.find(endWord)!=mp.end())
        {
            vector<string> seq={endWord};
            dfs(endWord,beginWord,seq);
        }
        return ans;
    }
};
