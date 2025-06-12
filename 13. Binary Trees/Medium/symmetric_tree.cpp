// Input:
// root = [1,2,2,3,4,4,3]
// Output:
// true
// Explanation:
//      1
//    /   \
//   2     2
//  / \   / \
// 3   4 4   3

bool isSymmetric(TreeNode* root)
{
    if(root==NULL)
        return true;
    return isSameTree(root->left,root->right);
}

bool isSameTree(TreeNode* p,TreeNode* q)
{
    if(p==NULL || q==NULL)
        return (p==q);
    if(p->val==q->val)
    {
        bool leftRight=isSameTree(p->left,q->right);
        bool rightLeft=isSameTree(p->right,q->left);
        return leftRight && rightLeft;
    }
    return false;
}
