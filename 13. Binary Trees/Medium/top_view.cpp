// Input:
// root = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
// Output:
// [2, 1, 3, 6]
// Explanation:
//   1
//  / \
// 2   3
//  \
//   4
//    \
//     5
//      \
//       6
// Node 1 is the root and visible.
// Node 2 is the left child and visible from the left side.
// Node 3 is the right child and visible from the right side.
// Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view.

void preorder(Node* root,int vertical,int level,map<int,pair<int,int>>& mp)
{
    if(root==NULL)
        return;
    if(mp.find(vertical)==mp.end() || level<mp[vertical].first)
        mp[vertical]={level,root->data};
    preorder(root->left,vertical-1,level+1,mp);
    preorder(root->right,vertical+1,level+1,mp);
}

vector<int> topView(Node* root)
{
    vector<int>ans;
    map<int,pair<int,int>>mp;
    preorder(root,0,0,mp);
    for(auto it:mp)
        ans.push_back(it.second.second);
    return ans;
}
