// Input:
// nums = [3,10,5,25,2,8]
// Output:
// 28
// Explanation:
// The maximum result is 5 XOR 25 = 28.

class Node
{
public:
    Node* links[2];

    Node()
    {
        links[0]=NULL;
        links[1]=NULL;
    }

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

    ~Node()
    {
        delete links[0];
        delete links[1];
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
    int findMaximumXOR(vector<int>& nums)
    {
        int maxi=0;
        Trie* trie=new Trie();
        trie->insert(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            maxi=max(trie->getMaxXOR(nums[i]),maxi);
            trie->insert(nums[i]);
        }
        delete trie;
        return maxi;
    }
};
