class Solution {
public:
    int minPartitions(string n) {
        int m = n.length();
        int result = 0;
        for(int i=0;i<m;i++){
            result = max(result,n[i]-'0');
        }
        return result;
    }
};