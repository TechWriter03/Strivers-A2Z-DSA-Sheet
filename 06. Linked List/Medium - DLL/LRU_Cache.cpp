class Node
{
public:
    int key,val;
    Node* next;
    Node* prev;

    Node(int key,int val)
    {
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache
{
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>mp;
    
    LRUCache(int capacity)
    {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void deleteNode(Node* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void insertFirst(Node* node)
    {
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
    }

    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            deleteNode(node);
            insertFirst(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key,int value)
    {
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            node->val=value;
            deleteNode(node);
            insertFirst(node);
        }
        else
        {
            if(mp.size()==capacity)
            {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            Node* node=new Node(key,value);
            mp[key]=node;
            insertFirst(node);
        }
    }
};
