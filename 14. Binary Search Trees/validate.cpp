// Input:
// root = [5,1,4,null,null,3,6]
// Output:
// false
// Explanation:
// The root node's value is 5 but its right child's value is 4.

bool isValid(TreeNode* root,long minVal,long maxVal)
{
    if(root==NULL)
        return true;
    int currVal=root->val;
    if(currVal<=minVal || currVal>=maxVal)
        return false;
    int left=isValid(root->left,minVal,currVal);
    int right=isValid(root->right,currVal,maxVal);
    return left && right;
}

bool isValidBST(TreeNode* root)
{
    cout<<INT_MAX;
    return isValid(root,LONG_MIN,LONG_MAX);    
}
