// Input:
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Output:
// [3,9,20,null,null,15,7]
// Explanation:
//   3
//  / \
// 9  20
//    / \
//   15  7

TreeNode* build(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd,unordered_map<int,int>& mp)
{
    if(preStart>preEnd || inStart>inEnd)
        return NULL;
    TreeNode* root=new TreeNode(preorder[preStart]);
    int inRoot=mp[root->val],leftLen=inRoot-inStart;
    root->left=build(preorder,inorder,preStart+1,preStart+leftLen,inStart,inRoot-1,mp);
    root->right=build(preorder,inorder,preStart+leftLen+1,preEnd,inRoot+1,inEnd,mp);
    return root;
}

TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder)
{
    unordered_map<int,int>mp;
    int m=preorder.size(),n=inorder.size();
    for(int i=0;i<n;i++)
        mp[inorder[i]]=i;
    return build(preorder,inorder,0,m-1,0,n-1,mp);
}
