// Input:
// root = [1,2,3,4,5]
// Output:
// 3
// Explanation:
//     1
//    / \
//   2   3
//  / \
// 4   5    
// 3 is the length of the path [4,2,1,3] or [5,2,1,3].

int diameterOfBinaryTree(TreeNode* root)
{
    int diameter=0;
    height(root,diameter);
    return diameter;
}

int height(TreeNode* root,int& diameter)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left,diameter);
    int rh=height(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}
