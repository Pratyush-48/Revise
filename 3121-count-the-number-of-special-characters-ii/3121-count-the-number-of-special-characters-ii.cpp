class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lower(26,-1);
        vector<int>upper(26,-1);
        int n = word.length();
        for(int i=0;i<n;i++){
            char it = word[i];
            if(it>='a' && it<='z'){
                lower[it-'a'] = i;
            }
            else if(upper[it-'A']==-1){
                upper[it-'A'] = i;
            }
        }
        int result = 0;
        for(int i=0;i<26;i++){
            if(lower[i]!=-1 && upper[i]!=-1 && lower[i]<upper[i]) result++;
        }
        return result;
    }
};