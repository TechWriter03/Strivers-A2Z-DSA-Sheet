// Input:
// root = [5,3,6,2,4,null,7]
// key = 3
// Output:
// [5,4,6,2,null,null,7]
// Explanation:
// Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

TreeNode* help(TreeNode* root)
{
    if(root->left==NULL)
        return root->right;
    else if(root->right==NULL)
        return root->left;
    TreeNode* lastRight=root->left;
    while(lastRight->right)
        lastRight=lastRight->right;
    lastRight->right=root->right;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root,int key)
{
    if(root==NULL)
        return NULL;
    else if(root->val==key)
        return help(root);
    TreeNode* temp=root;
    while(temp)
    {
        if(temp->val>key)
        {
            if(temp->left && temp->left->val==key)
            {
                temp->left=help(temp->left);
                break;
            }
            else
            {
                temp=temp->left;
            }
        }
        else
        {
            if(temp->right && temp->right->val==key)
            {
                temp->right=help(temp->right);
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
    }
    return root;
}
