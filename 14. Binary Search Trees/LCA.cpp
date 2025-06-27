// Input:
// root = [6,2,8,0,4,7,9,null,null,3,5]
// p = 2
// q = 8
// Output:
// 6

TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root==NULL)
        return NULL;
    if(root->val>p->val && root->val>q->val)
        return lowestCommonAncestor(root->left,p,q);
    if(root->val<p->val && root->val<q->val)
        return lowestCommonAncestor(root->right,p,q);
    return root;
}
