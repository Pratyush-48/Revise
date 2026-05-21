struct node{
    vector<node*>child;
};
class Solution {
public:
    node* getNode(){
        node* new_node = new node();
        new_node->child.resize(10,NULL);
        return new_node;
    }
    void insert(int num,node*root){
        string str = to_string(num);
        node* crawler = root;
        int n = str.length();
        for(int i=0;i<n;i++){
            int idx = str[i]-'0';
            if(crawler->child[idx]==NULL){
                crawler->child[idx] = getNode();
            }
            crawler = crawler->child[idx];
        }
    }
    int findd(int num,node*root){
        string str = to_string(num);
        node* crawler = root;
        int n = str.length();
        for(int i=0;i<n;i++){
            int idx = str[i]-'0';
            if(crawler->child[idx]==NULL) return i;
            crawler = crawler->child[idx];
        }
        return n;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        node* root = getNode();
        for(auto &it:arr1){
            insert(it,root);
        }
        int result = 0;
        for(auto &it:arr2){
            result = max(result,findd(it,root));
        }
        return result;
    }
};