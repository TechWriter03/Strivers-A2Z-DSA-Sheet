// Input:
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output:
// [null, null, true, false, true, null, true]
// Explanation:
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True

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

    bool getEnd()
    {
        return flag;
    }

    void setEnd()
    {
        flag=true;
    }
};

class Trie
{
public:
    Node* root;

    Trie()
    {
        root=new Node();
    }
    
    void insert(string word)
    {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsKey(word[i]))
                temp->put(word[i]);
            temp=temp->get(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(string word)
    {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsKey(word[i]))
                return false;
            temp=temp->get(word[i]);
        }
        return temp->getEnd();
    }
    
    bool startsWith(string prefix)
    {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->containsKey(prefix[i]))
                return false;
            temp=temp->get(prefix[i]);
        }
        return true;
    }
};
