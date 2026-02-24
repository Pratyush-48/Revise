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
    void sum_leaf(TreeNode*root,vector<int>&res,int &result){
        if(!root) return;
        res.push_back(root->val);
        if(!root->left && !root->right){
            int v = 0;
            for(int i=0;i<res.size();i++){
                v*=2;
                v += res[i];
            }
            result += v;
            res.pop_back();
            return;
        }
        sum_leaf(root->left,res,result);
        sum_leaf(root->right,res,result);
        res.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        vector<int>res;
        sum_leaf(root,res,result);
        return result;
    }
};