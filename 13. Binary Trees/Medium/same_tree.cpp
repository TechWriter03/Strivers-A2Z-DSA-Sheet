// Input:
// p = [1,2,3]
// q = [1,2,3]
// Output:
// true
// Explanation:
//   1      1
//  / \    / \
// 2   3  2   3

bool isSameTree(TreeNode* p,TreeNode* q)
{
    if(p==NULL || q==NULL)
        return p==q;
    if(p->val==q->val)
    {
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        return left && right;
    }
    return false;
}
