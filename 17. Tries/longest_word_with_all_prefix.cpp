// Input:
// words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
// Output:
// "pros" 
// Explanation:
// "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present.

class Node
{
public:
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch)
    {
        links[ch-'a']=new Node();
    }
    
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
    void setEnd()
    {
        flag=true;
    }
    
    bool getEnd()
    {
        return flag;
    }
};

class Trie
{
public:
    Node* root=new Node();
    
    void insert(string word)
    {
        Node* temp=root;
        for(auto i:word)
        {
            if(!temp->containsKey(i))
                temp->put(i);
            temp=temp->get(i);
        }
        temp->setEnd();
    }
    
    bool checkAllPrefix(string word)
    {
        Node* temp=root;
        for(auto i:word)
        {
            if(!temp->containsKey(i))
                return false;
            temp=temp->get(i);
            if(!temp->getEnd())
                return false;
        }
        return true;
    }
};

class Solution
{
public:
    string longestValidWord(vector<string>& words)
    {
        string longest="";
        Trie* trie=new Trie();
        for(auto it:words)
        {
            trie->insert(it);
        }
        for(auto it:words)
        {
            if(trie->checkAllPrefix(it))
            {
                if(it.size()>longest.size())
                    longest=it;
                else if(it.size()==longest.size() && it<longest)
                    longest=it;
            }
        }
        return longest;
    }
};
