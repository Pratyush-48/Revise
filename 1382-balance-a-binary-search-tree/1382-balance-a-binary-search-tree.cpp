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
    vector<int>nums;
    void inorder(TreeNode*root){
        if(!root) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* form(int i,int j){
        if(i>j) return NULL;
        int mid = (i+j)/2;
        TreeNode* now = new TreeNode(nums[mid]);
        now->left = form(i,mid-1);
        now->right = form(mid+1,j);
        return now;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return form(0,nums.size()-1);
    }
};