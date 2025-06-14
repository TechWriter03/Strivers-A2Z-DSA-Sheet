// Input:
// root = [3,9,20,null,null,15,7]
// Output:
// [[9],[3,15],[20],[7]]
// Explanation:
//     3
//    / \
//   9  20
//     / \
//    15  7
// Column -1: Only node 9 is in this column.
// Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
// Column 1: Only node 20 is in this column.
// Column 2: Only node 7 is in this column.

void preorder(TreeNode* root,int vertical,int level,map<int,map<int,multiset<int>>>& mp)
{
    if(root==NULL)
        return;
    mp[vertical][level].insert(root->val);
    preorder(root->left,vertical-1,level+1,mp);
    preorder(root->right,vertical+1,level+1,mp);
}

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    vector<vector<int>>ans;
    map<int,map<int,multiset<int>>>mp;
    preorder(root,0,0,mp);
    for(auto it:mp)
    {
        vector<int>temp;
        for(auto i:it.second)
            for(auto j:i.second)
                temp.push_back(j);
        ans.push_back(temp);
    }
    return ans;
}
