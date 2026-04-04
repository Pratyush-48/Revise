class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
         int n = encodedText.length();
         int m = ceil(n/(double)rows);
        vector<vector<char>>txt(rows,vector<char>(m,' '));
        int k = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<m;j++){
                txt[i][j] = encodedText[k];
                k++;
            }
        }
        string result;
        int i = 0;
        int j = 0;
        k = 0;
        while(j<m){
            i = 0;
            k = j;
            while(i<rows && k<m){
                result += txt[i][k];
                i++;
                k++;
            }
            j++;
        }
        while(!result.empty() && result.back()==' ') result.pop_back();
        return result;
    }
};