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
    bool result;
    int solve(TreeNode*root){
        if(!root || !result) return 0;
        int left = 1+solve(root->left);
        int right = 1+solve(root->right);
        if(abs(right-left)>1){
            result = false;
        }
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        result = true;
        solve(root);
        return result;
    }
};