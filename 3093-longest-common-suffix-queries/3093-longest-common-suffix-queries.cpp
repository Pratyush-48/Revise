struct Node{
Node* child[26];
int idx;
};
class Solution {
public:
    vector<Node*> gc;
    Node* getNode(){
        Node* temp = new Node();
        for(int i=0;i<26;i++){
            temp->child[i] = NULL;
        }
        temp->idx = -1;
        gc.push_back(temp);
        return temp;
    }
    void insert_trie(string &s,Node* root,int k,vector<string>& wordsContainer){
        int n = s.length();
        Node* crawler = root;
        for(int i=0;i<n;i++){
            int idx = s[i]-'a';
            if(crawler->child[idx]==NULL){
                crawler->child[idx] = getNode();
                crawler->child[idx]->idx = k;
            }
            else if(wordsContainer[crawler->child[idx]->idx].length()>n){
                crawler->child[idx]->idx = k;
            }
            crawler = crawler->child[idx];
        }
    }
    int query_trie(string &s,Node*root){
        int res = -1;
        int n = s.length();
        Node* crawler = root;
        for(int i=0;i<n;i++){
            int idx = s[i]-'a';
            if(crawler->child[idx]==NULL) return res;
            res = crawler->child[idx]->idx;
            crawler = crawler->child[idx];
        }
        return res;
    }
    void rev(string &s){
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        gc.clear();
        Node* root = getNode();
        int n = wordsContainer.size();
        int mini = INT_MAX;
        int idx = -1;
        for(int i=0;i<n;i++){
            string s = wordsContainer[i];
            rev(s);
            if(mini>s.length()){
                mini = s.length();
                idx = i;
            }
            insert_trie(s,root,i,wordsContainer);
        }
        vector<int>result;
        for(auto &it:wordsQuery){
            string s = it;
            rev(s);
            int i = query_trie(s,root);
            if(i==-1){
                result.push_back(idx);
            }
            else{
                result.push_back(i);
            }
        }
        for(Node* node : gc){
            delete node;
        }
        gc.clear();
        return result;
    }
};