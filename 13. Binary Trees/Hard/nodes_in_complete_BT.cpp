// Input:
// root = [1,2,3,4,5,6]
// Output:
// 6
// Explanation:
//      1
//    /   \
//   2     3
//  / \   /
// 4   5 6

int leftHeight(TreeNode* node)
{
    int height=0;
    while(node)
    {
        height++;
        node=node->left;
    }
    return height;
}

int rightHeight(TreeNode* node)
{
    int height=0;
    while(node)
    {
        height++;
        node=node->right;
    }
    return height;
}

int countNodes(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int lh=leftHeight(root);
    int rh=rightHeight(root);
    if(lh==rh)
        return (1<<lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
}
