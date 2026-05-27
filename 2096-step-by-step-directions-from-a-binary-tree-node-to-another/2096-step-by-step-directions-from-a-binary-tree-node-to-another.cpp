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
    void traverse(TreeNode*root,bool &found,string &res,int val){
        if(!root || found) return;
        if(val==root->val){
            found = true;
            return;
        }
        res+='L';
        traverse(root->left,found,res,val);
        if(found) return;
        res.pop_back();
        res+='R';
        traverse(root->right,found,res,val);
        if(found) return;
        res.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start = "";
        string dest = "";
        bool s_val = false;
        bool d_val = false;
        traverse(root,s_val,start,startValue);
        traverse(root,d_val,dest,destValue);
        string result = "";
        int i = 0;
        int j = 0;
        while(i<start.length() && j<dest.length()){
            if(start[i]==dest[j]){
                i++;
                j++;
            }
            else break;
        }
        for(int k=i;k<start.length();k++){
            result+='U';
        }
        for(int k=j;k<dest.length();k++){
            result+=dest[k];
        }
        return result;
    }
};