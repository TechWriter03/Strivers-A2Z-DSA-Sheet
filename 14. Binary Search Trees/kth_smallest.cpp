// Input:
// root = [5,3,6,2,4,null,null,1]
// k = 3
// Output:
// 3

void dfs(TreeNode* root,vector<int>& inorder)
{
    if(root==NULL)
        return;
    dfs(root->left,inorder);
    inorder.push_back(root->val);
    dfs(root->right,inorder);
}

int kthSmallest(TreeNode* root,int k)
{
    vector<int>inorder;
    dfs(root,inorder);
    return inorder[k-1];
}
