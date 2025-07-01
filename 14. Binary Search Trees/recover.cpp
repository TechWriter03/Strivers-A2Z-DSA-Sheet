// Input:
// root = [3,1,4,null,null,2]
// Output:
// [2,1,4,null,null,3]
// Explanation:
// 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

class Solution
{
public:
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* last=NULL;

    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        if(prev && prev->val>root->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
            {
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root)
    {
        inorder(root);
        if(first && last)
            swap(first->val,last->val);
        else if(first && middle)
            swap(first->val,middle->val);
    }
};
