// Input:
// root = [3,5,1,6,2,0,8,null,null,7,4]
// target = 5
// k = 2
// Output:
// [7,4,1]
// Explanation:
// The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
//      3 
//    /   \
//   5     1
//  / \   / \
// 6   2 0   8
//    / \
//   7   4

void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
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

vector<int> distanceK(TreeNode* root,TreeNode* target,int k)
{
    vector<int>ans;
    unordered_map<TreeNode*,TreeNode*>parent;
    unordered_map<TreeNode*,int>visited;
    findParent(root,parent);
    int dist=0;
    queue<TreeNode*>q;
    visited[target]=1;
    q.push(target);
    while(!q.empty())
    {
        if(dist==k)
            break;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(parent[temp] && visited[parent[temp]]==0)
            {
                visited[parent[temp]]=1;
                q.push(parent[temp]);
            }
            if(temp->left && visited[temp->left]==0)
            {
                visited[temp->left]=1;
                q.push(temp->left);
            }
            if(temp->right && visited[temp->right]==0)
            {
                visited[temp->right]=1;
                q.push(temp->right);
            }
        }
        dist++;
    }
    while(!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}
