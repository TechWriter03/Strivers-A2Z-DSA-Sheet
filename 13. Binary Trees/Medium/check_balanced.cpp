// Input:
// root = [3,9,20,null,null,15,7]
// Output:
// true
// Explanation:
//   3
//  / \
// 9  20
//   /  \
//  15   7

bool isBalanced(TreeNode* root)
{
    return height(root)!=-1;
}

int height(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    if(lh==-1 || rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    return 1+max(lh,rh);
}
