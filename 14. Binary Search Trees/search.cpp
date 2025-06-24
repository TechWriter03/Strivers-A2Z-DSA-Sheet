// Input:
// root = [4,2,7,1,3]
// val = 2
// Output:
// [2,1,3]

TreeNode* searchBST(TreeNode* root, int val)
{
    while(root && root->val!=val)
    {
        if(root->val<val)
            root=root->right;
        else
            root=root->left;
    }
    return root;
}