class Node
{
public:
    Node* links[26];
    
    Node()
    {
        for(int i=0;i<26;i++)
            links[i]=NULL;
    }
    
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
    
    ~Node()
    {
        for(int i=0;i<26;i++)
            delete links[i];
    }
};

int countDistinctSubstring(string s)
{
    int count=0;
    Node* root=new Node();
    for(int i=0;i<s.size();i++)
    {
        Node* temp=root;
        for(int j=i;j<s.size();j++)
        {
            if(!temp->containsKey(s[j]))
            {
                temp->put(s[j]);
                count++;
            }
            temp=temp->get(s[j]);
        }
    }
    delete root;
    return count+1;
}
