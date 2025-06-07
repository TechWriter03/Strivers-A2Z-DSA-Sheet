// Input:
// root = [1,null,2,3]
// Output:
// [3,2,1]
// Explanation:
// 1
//  \
//   2
//  /
// 3

void postorder(TreeNode* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int>ans;
    postorder(root,ans);
    return ans;   
}
