// Input:
// root = [-10,9,20,null,null,15,7]
// Output:
// 42
// Explanation:
//    -10
//    / \
//   9  20
//     / \
//    15  7
// The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

int maxPathSum(TreeNode* root)
{
    int maxi=INT_MIN;
    height(root,maxi);
    return maxi;
}

int height(TreeNode* root,int& maxi)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left,maxi);
    int rh=height(root->right,maxi);
    maxi=max(root->val+lh+rh,maxi);
    if(root->val+max(lh,rh)<0)
        return 0;
    return root->val+max(lh,rh);
}
