// Input:
// root = [1,2,3,4,5,6,7]
// Output:
// [4,2,6,3,7]
// Explanation:
//      1 
//    /   \
//   2     3
//  / \   / \
// 4   5 6   7

void preorder(Node* root,int vertical,int level,map<int,pair<int,int>>& mp)
{
    if(root==NULL)
        return;
    if(mp.find(vertical)==mp.end() || mp[vertical].first<=level)
        mp[vertical]={level,root->data};
    preorder(root->left,vertical-1,level+1,mp);
    preorder(root->right,vertical+1,level+1,mp);
}

vector<int> bottomView(Node* root)
{
    vector<int>ans;
    map<int,pair<int,int>>mp;
    preorder(root,0,0,mp);
    for(auto it:mp)
        ans.push_back(it.second.second);
    return ans;
}
