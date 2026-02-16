class Solution {
public:
    int reverseBits(int n) {
        long long result = 0;
        vector<int>bits;
        while(n){
            int m = n%2;
            n/= 2;
            bits.push_back(m);
        }
        //reverse(bits.begin(),bits.end());
        for(int i=0;i<bits.size();i++){
            result = result<<1;
            result += bits[i];
        }
        int d = 32-bits.size();
        while(d--){
            result <<= 1;
        }
        return result;
    }
};