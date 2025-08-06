// Input:
// nums = [0,1,2,3,4]
// queries = [[3,1],[1,3],[5,6]]
// Output:
// [3,3,7]
// Explanation:
// 1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
// 2) 1 XOR 2 = 3.
// 3) 5 XOR 2 = 7.

class Node
{
public:
    Node* links[2];

    bool containsKey(int bit)
    {
        return links[bit]!=NULL;
    }

    void put(int bit)
    {
        links[bit]=new Node();
    }

    Node* get(int bit)
    {
        return links[bit];
    }
};

class Trie
{
public:
    Node* root=new Node();

    void insert(int num)
    {
        Node* temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!temp->containsKey(bit))
                temp->put(bit);
            temp=temp->get(bit);
        }
    }

    int getMaxXOR(int num)
    {
        int maxi=0;
        Node* temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(temp->containsKey(1-bit))
            {
                maxi=maxi|(1<<i);
                temp=temp->get(1-bit);
            }
            else
            {
                temp=temp->get(bit);
            }
        }
        return maxi;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int>& nums,vector<vector<int>>& queries)
    {
        int n=queries.size();
        vector<int>ans(n);
        sort(nums.begin(),nums.end());
        vector<vector<int>>offQue;
        for(int i=0;i<n;i++)
            offQue.push_back({queries[i][1],queries[i][0],i});
        sort(offQue.begin(),offQue.end());
        int ind=0;
        Trie* trie=new Trie();
        for(auto q:offQue)
        {
            while(ind<nums.size() && nums[ind]<=q[0])
                trie->insert(nums[ind++]);
            if(ind==0)
                ans[q[2]]=-1;
            else
                ans[q[2]]=trie->getMaxXOR(q[1]);
        }
        return ans;
    }
};
