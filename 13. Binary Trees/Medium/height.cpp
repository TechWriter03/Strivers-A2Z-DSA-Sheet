// Input:
// root = [3,9,20,null,null,15,7]
// Output:
// 3
// Explanation:
//   3
//  / \
// 9  20
//   /  \
//  15   7

int height(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}
