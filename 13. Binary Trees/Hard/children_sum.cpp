// Input:
//      35
//     /  \
//   20   15
//  / \   / \
// 15  5 10  5
// Output:
// 1
// Explanation: 
// Here, every node is sum of its left and right child.

int isSumProperty(Node* root)
{
    if(root==NULL)
        return 1;
    int sum=0;
    if(root->left)
        sum+=root->left->data;
    if(root->right)
        sum+=root->right->data;
    if(root->data==sum || sum==0)
    {
        int left=isSumProperty(root->left);
        int right=isSumProperty(root->right);
        if(left && right)
            return 1;
    }
    return 0;
}
