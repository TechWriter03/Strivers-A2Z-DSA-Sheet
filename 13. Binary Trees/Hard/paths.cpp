// Input:
// root = [1,2,3,null,5]
// Output:
// ["1->2->5","1->3"]
// Explanation:
//   1
//  / \
// 2   3
//  \
//   5

void preorder(TreeNode* root,string path,vector<string>& ans)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(path+to_string(root->val));
        return;
    }
    preorder(root->left,path+to_string(root->val)+"->",ans);
    preorder(root->right,path+to_string(root->val)+"->",ans);
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string>ans;
    preorder(root,"",ans);
    return ans;
}
