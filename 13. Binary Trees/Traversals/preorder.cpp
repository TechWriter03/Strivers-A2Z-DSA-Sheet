// Input:
// root = [1,null,2,3]
// Output:
// [1,2,3]
// Explanation:
// 1
//  \
//   2
//  /
// 3

void preorder(TreeNode* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    ans.push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int>ans;
    preorder(root,ans);
    return ans;   
}
