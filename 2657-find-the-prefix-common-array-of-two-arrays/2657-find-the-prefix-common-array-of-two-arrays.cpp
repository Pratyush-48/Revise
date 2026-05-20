class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;
        int count = 0;
        vector<int>C;
        int n = A.size();
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(A[i]==B[i]){
                count++;
            }
            else{
                if(mp[A[i]]==2) count++;
                if(mp[B[i]]==2) count++;
            }
            C.push_back(count);
        }
        return C;
    }
};