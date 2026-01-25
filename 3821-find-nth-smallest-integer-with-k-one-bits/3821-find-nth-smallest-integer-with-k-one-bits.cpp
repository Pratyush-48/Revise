class Solution {
public:
    long long combi[60][60];
    void pre(){
        for(int i=0;i<60;i++){
            combi[i][0] = 1;
            for(int j=1;j<=i;j++){
                combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
            }
        }
    }
    long long nthSmallest(long long n, int k) {
        long long result = 0;
        pre();
        for(int i=55;i>=0;i--){
            long long v = (i>=k) ? combi[i][k] : 0;
            if(n>v){
                result |= (1LL << i);
                n-=v;
                k--;
            }
        }
        return result;
    }
};