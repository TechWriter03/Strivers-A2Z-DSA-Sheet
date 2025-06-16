// Input:
// root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output:
// 3
// Explanation:
//      3 
//    /   \
//   5     1
//  / \   / \
// 6   2 0   8
//    / \
//   7   4

TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(root==NULL || root==p || root==q)
        return root;
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(left && right)
        return root;
    else if(left==NULL)
        return right;
    else
        return left;
}
