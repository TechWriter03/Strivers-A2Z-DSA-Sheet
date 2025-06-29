// Input:
// preorder = [8,5,1,7,10,12]
// Output:
// [8,5,10,1,7,null,12]

TreeNode* build(int bound,int& ind,vector<int>& preorder)
{
    if(ind==preorder.size() || preorder[ind]>bound)
        return NULL;
    TreeNode* root=new TreeNode(preorder[ind++]);
    root->left=build(root->val,ind,preorder);
    root->right=build(bound,ind,preorder);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    int ind=0;
    return build(INT_MAX,ind,preorder);
}
