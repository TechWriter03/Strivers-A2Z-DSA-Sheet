// Input:
// root = [1, 2, 3, 4, 5, 6, 7]
// target = 2
// Output:
// 3
// Explanation:
//      1 
//    /   \
//   2     3
//  / \   / \
// 4   5 6   7
// Initially 2 is set to fire at 0 sec 
// At 1 sec: Nodes 4, 5, 1 catches fire.
// At 2 sec: Node 3 catches fire.
// At 3 sec: Nodes 6, 7 catches fire.
// It takes 3s to burn the complete tree.

Node* findTarget(Node* root,int target)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        if(temp->data==target)
            return temp;
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

void findParent(Node* root,unordered_map<Node*,Node*>& parent)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();
        if(node->left)
        {
            parent[node->left]=node;
            q.push(node->left);
        }
        if(node->right)
        {
            parent[node->right]=node;
            q.push(node->right);
        }
    }
}

int minTime(Node* root,int target)
{
    int time=0;
    Node* targetNode=findTarget(root,target);
    unordered_map<Node*,Node*>parent;
    findParent(root,parent);
    unordered_map<Node*,int>visited;
    queue<Node*>q;
    visited[targetNode]=1;
    q.push(targetNode);
    while(!q.empty())
    {
        int size=q.size();
        int flag=0;
        for(int i=0;i<size;i++)
        {
            Node* temp=q.front();
            q.pop();
            if(parent[temp] && visited[parent[temp]]==0)
            {
                visited[parent[temp]]=1;
                q.push(parent[temp]);
                flag=1;
            }
            if(temp->left && visited[temp->left]==0)
            {
                visited[temp->left]=1;
                q.push(temp->left);
                flag=1;
            }
            if(temp->right && visited[temp->right]==0)
            {
                visited[temp->right]=1;
                q.push(temp->right);
                flag=1;
            }
        }
        if(flag)
            time++;
    }
    return time;
}
