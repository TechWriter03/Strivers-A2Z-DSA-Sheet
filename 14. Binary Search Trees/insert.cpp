// Input:
// root = [4,2,7,1,3]
// val = 5
// Output:
// [4,2,7,1,3,5]

TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if(root==NULL)
        return new TreeNode(val);
    TreeNode* temp=root;
    while(temp)
    {
        if(temp->val>val)
        {
            if(temp->left)
            {
                temp=temp->left;
            }
            else
            {
                temp->left=new TreeNode(val);
                break;
            }
        }
        else
        {
            if(temp->right)
            {
                temp=temp->right;
            }
            else
            {
                temp->right=new TreeNode(val);
                break;
            }
        }
    }
    return root;
}