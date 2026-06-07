/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recc(unordered_map<int,vector<vector<int>>>&adj,int val){
        TreeNode* root = new TreeNode(val);
        for(auto &ch:adj[val]){
            int chi = ch[0];
            int l = ch[1];
            if(l==1){
                root->left = recc(adj,chi);
            }
            else{
                root->right =  recc(adj,chi);
            }
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<vector<int>>>adj;
        unordered_set<int>child;
        for(auto &it:descriptions){
            int p = it[0];
            int c = it[1];
            int l = it[2];
            adj[p].push_back({c,l});
            child.insert(c);
        }
        int root;
        for(auto &it:adj){
            int p = it.first;
            if(child.find(p)==child.end()){
                root = p;
                break;
            }
        }
        TreeNode* Root = recc(adj,root);
        return Root;
    }
};