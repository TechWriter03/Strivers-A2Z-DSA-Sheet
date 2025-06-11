// Input:
// root = [3,9,20,null,null,15,7]
// Output:
// [[3],[20,9],[15,7]]
// Explanation:
//     3
//    / \
//   9  20
//     / \
//    15  7

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>>ans;
    if(root==NULL)
        return ans;
    queue<TreeNode*>q;
    q.push(root);
    int count=0;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++)
        {
            TreeNode* node=q.front();
            q.pop();
            if(count%2==0)
                level[i]=node->val;
            else
                level[size-i-1]=node->val;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        ans.push_back(level);
        count++;
    }
    return ans;
}
