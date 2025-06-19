// Input:
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Output:
// [3,9,20,null,null,15,7]
// Explanation:
//   3
//  / \
// 9  20
//    / \
//   15  7

TreeNode* build(vector<int>& inorder,vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd,unordered_map<int,int>& mp)
{
    if(inStart>inEnd ||postStart>postEnd)
        return NULL;
    TreeNode* root=new TreeNode(postorder[postEnd]);
    int inRoot=mp[root->val],rightLen=inEnd-inRoot;
    root->left=build(inorder,postorder,inStart,inRoot-1,postStart,postEnd-rightLen-1,mp);
    root->right=build(inorder,postorder,inRoot+1,inEnd,postEnd-rightLen,postEnd-1,mp);
    return root;
}

TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder)
{
    unordered_map<int,int>mp;
    int m=inorder.size(),n=postorder.size();
    for(int i=0;i<m;i++)
        mp[inorder[i]]=i;
    return build(inorder,postorder,0,m-1,0,n-1,mp);
}
